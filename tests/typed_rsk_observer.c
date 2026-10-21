#include "rsk.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void list(const int *values,int count)
{
    putchar('[');
    for(int index=0;index<count;++index) printf("%s%d",index?", ":"",values[index]);
    putchar(']');
}

static void rows(const Tableau *filling)
{
    for(int row=0;row<filling->shape.count;++row) {
        if(row) putchar(';');
        for(int column=0;column<filling->shape.rows[row];++column)
            printf("%s%d",column?",":"",filling->entries[row][column]);
    }
}

static void observe(MathStatus status,const RSKTrace *trace)
{
    if(status!=YT_OK) { puts("UNEXPECTED_NATIVE_REJECTION"); exit(1); }
    printf("S=%d|P=",trace->step); rows(&trace->p);
    printf("|Q="); rows(&trace->q);
    printf("|PATH=");
    for(int index=0;index<trace->path_count;++index)
        printf("%s%d,%d",index?";":"",trace->path[index].row,trace->path[index].column);
    printf("|V=%d\n",trace->inserted);
}

static void word_case(const int *values,int count,bool permutation)
{
    printf("%s ",permutation?"PERMUTATION":"WORD"); list(values,count); putchar('\n');
    for(int step=0;step<=count;++step) {
        RSKTrace trace;
        MathStatus status;
        if(permutation) {
            Permutation input={.count=count};
            for(int index=0;index<count;++index) input.values[index]=values[index];
            status=rsk_permutation(&input,step,&trace);
        } else {
            Word input={.count=count};
            for(int index=0;index<count;++index) input.letters[index]=values[index];
            status=rsk_word(&input,step,&trace);
        }
        observe(status,&trace);
    }
}

static void words_of_length(int *values,int count,int position)
{
    if(position==count) { word_case(values,count,false); return; }
    for(int value=1;value<=3;++value) {
        values[position]=value;
        words_of_length(values,count,position+1);
    }
}

static void permutations_of_length(int *values,int count,int position)
{
    if(position==count) { word_case(values,count,true); return; }
    for(int value=1;value<=count;++value) {
        bool used=false;
        for(int previous=0;previous<position;++previous) if(values[previous]==value) used=true;
        if(!used) { values[position]=value; permutations_of_length(values,count,position+1); }
    }
}

static void biword_case(const Biletter *letters,int count)
{
    Biword input={.count=count};
    printf("BIWORD [");
    for(int index=0;index<count;++index) {
        input.letters[index]=letters[index];
        printf("%s(%d, %d)",index?", ":"",letters[index].top,letters[index].bottom);
    }
    puts("]");
    for(int step=0;step<=count;++step) {
        RSKTrace trace;
        MathStatus status=rsk_biword(&input,step,&trace);
        observe(status,&trace);
    }
}

static void matrix_case(const NatMatrix *input)
{
    int count=0;
    printf("MATRIX [");
    for(int row=0;row<input->row_count;++row) {
        if(row) printf(", ");
        list(input->entries[row],input->column_count);
        for(int column=0;column<input->column_count;++column) count+=input->entries[row][column];
    }
    puts("]");
    for(int step=0;step<=count;++step) {
        RSKTrace trace;
        MathStatus status=rsk_matrix(input,step,&trace);
        observe(status,&trace);
    }
}

int main(void)
{
    int values[64]={0};
    for(int count=0;count<=4;++count) words_of_length(values,count,0);
    word_case((int[]){INT_MAX,1,INT_MAX},3,false);
    for(int index=0;index<64;++index) values[index]=1;
    word_case(values,64,false);
    for(int count=0;count<=5;++count) permutations_of_length(values,count,0);
    for(int index=0;index<64;++index) values[index]=64-index;
    word_case(values,64,true);
    biword_case(NULL,0);
    biword_case((Biletter[]){{1,1}},1);
    biword_case((Biletter[]){{1,1},{1,1},{1,2},{2,1},{2,2}},5);
    biword_case((Biletter[]){{1,3},{2,1},{2,2},{3,1}},4);
    biword_case((Biletter[]){{INT_MAX,INT_MAX}},1);
    matrix_case(&(NatMatrix){0});
    for(int first=0;first<=2;++first) for(int second=0;second<=2;++second)
        for(int third=0;third<=2;++third) for(int fourth=0;fourth<=2;++fourth) {
            NatMatrix input={.row_count=2,.column_count=2};
            input.entries[0][0]=first; input.entries[0][1]=second;
            input.entries[1][0]=third; input.entries[1][1]=fourth;
            matrix_case(&input);
        }
    NatMatrix boundary={.row_count=1,.column_count=1};
    boundary.entries[0][0]=64;
    matrix_case(&boundary);
    return 0;
}
