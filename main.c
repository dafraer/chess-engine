#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "engine/engine.h"
#include "helpers/helpers.h"
#include "bitboard/bitboard.h"

int main() {
    bitboard *b = new_board("fen_pos");
    engine *e = new_engine(b);
    run(e);
    free(e);
    return 0;
}

