#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "engine/engine.h"
#include "bitboard/bitboard.h"
#define START_FEN_POS "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"


//Returns a new empty bitboard
bitboard* new_board() {
    bitboard *b = malloc(sizeof(bitboard));
    return b;
}

//Checks if the square is occupied
bool is_occupied(ull position, ull piece) {
    return position & piece;
}

//Sets up the bitboard based on the provided fen position string
//If fen position string is null, returns starting position
void setup_pos(bitboard *b, char *fen_pos, char *side_to_move, char *castling_availability, char *enpassant_square, int half_move_clock, int move_num) {
    if (!fen_pos) fen_pos = START_FEN_POS;
    if (!side_to_move) side_to_move = "w";
    if (!castling_availability) castling_availability = "KQkq";
    if (!enpassant_square) enpassant_square = "-";
    //TODO finish setting up the position

}