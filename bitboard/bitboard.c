#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "engine/engine.h"
#include "bitboard/bitboard.h"

bitboard* new_board(char* fen_pos) {
    return NULL;
}

bool is_occupied(ull position, ull piece) {
    return position & piece;
}