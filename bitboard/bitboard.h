#ifndef BITBOARD_H
#define BITBOARD_H
#define ull unsigned long long
typedef struct {
    ull white_pawn;
    ull white_king;
    ull white_queen;
    ull white_bishop;
    ull white_knight;
    ull white_rook;
    ull black_pawn;
    ull black_king;
    ull black_queen;
    ull black_bishop;
    ull black_knight;
    ull black_rook;
} bitboard;

bool is_occupied(ull position, ull piece);
bitboard* new_board(char* fen_pos);
#endif