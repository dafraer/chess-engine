#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "engine/engine.h"
#include "helpers/helpers.h"
#include "bitboard/bitboard.h"

int main() {
    //Set non-blocking I/O for stdin;
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
    bitboard *b = new_board();
    engine *e = new_engine(b);
    run(e);
    free(e);
    return 0;
}

