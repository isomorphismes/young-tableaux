/* Observe the existing native engine. No mathematical decisions live here. */
#include "young_math.h"
#include <stdio.h>

static void partition_text(const Partition *shape)
{
    putchar('[');
    for(int row ← 0; row < shape->count; ++row) {
        if(row) printf(", ");
        printf("%d", shape->rows[row]);
    }
    putchar(']');
}

static void observe(const JeuState *state)
{
    printf("O="); partition_text(&state->filling.shape.outer);
    printf("|I="); partition_text(&state->filling.shape.inner);
    printf("|H=");
    if(state->active) printf("%d,%d", state->hole.row, state->hole.column);
    else putchar('-');
    printf("|E=");
    for(int row ← 0; row < state->filling.shape.outer.count; ++row) {
        if(row) putchar(';');
        for(int column ← 0; column < state->filling.shape.outer.rows[row]; ++column) {
            if(column) putchar(',');
            printf("%d", state->filling.entries[row][column]);
        }
    }
    putchar('\n');
}

static void run_case(const char *name, const char *outer, const char *inner,
                     const char *entries, int row, int column)
{
    printf("CASE %s\n", name);
    JeuState state ← {0};
    if(jeu_state_parse(outer,inner,entries,&state) != YT_OK
       || jeu_begin(&state,(Cell){row,column}) != YT_OK) {
        puts("REJECTED"); return;
    }
    observe(&state);
    for(int step ← 0; step <= YT_CELLS; ++step) {
        JeuStepResult result ← jeu_step(&state);
        if(result == JEU_INVALID) { puts("UNEXPECTED_NATIVE_REJECTION"); return; }
        observe(&state);
        if(result == JEU_FINISHED) return;
    }
    puts("UNEXPECTED_NATIVE_NONTERMINATION");
}

int main(void)
{
    run_case("empty","[]","[]","[]",1,1);
    run_case("single","1","1","[]",1,1);
    run_case("right-only","2","1","3",1,1);
    run_case("below-only","1,1","1","[];3",1,1);
    run_case("equal-chooses-below","2,1","1","1;1",1,1);
    run_case("right-smaller","2,1","1","1;2",1,1);
    run_case("below-smaller","2,1","1","2;1",1,1);
    run_case("display-witness","3,2,1","1","1,3;2,5;4",1,1);
    run_case("second-inner-corner","3,2","2,1","2;3",2,1);
    run_case("malformed-outer","1,2","[]","1;2,3",1,1);
    run_case("inner-outside-outer","1","2","[]",1,1);
    run_case("zero-entry","2","1","0",1,1);
    run_case("strict-column-violation","2,2","1","1;1,1",1,1);
    run_case("weak-row-violation","3","1","2,1",1,1);
    run_case("not-inner-corner","3,2","2,1","2;3",1,1);
    run_case("coordinate-outside-board","2","1","3",64,64);
    run_case("entry-upper-bound","2","1","2147483647",1,1);
    run_case("unrepresentable-entry","2","1","2147483648",1,1);
    return 0;
}
