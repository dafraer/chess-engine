#ifndef ENGINE_H
#define ENGINE_H
#include "bitboard/bitboard.h"
typedef struct {
    bitboard *board;
    int hash_size;
} engine;
engine* new_engine(bitboard *board);
void run(engine *e);
#endif