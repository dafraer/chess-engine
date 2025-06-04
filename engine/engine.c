#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "engine.h"
#include "bitboard/bitboard.h"
#include "helpers/helpers.h"

//GUI to engine commands
#define STARTPOS "startpos"
#define UCI "uci"
#define DEBUG "debug"
#define IS_READY "isready"
#define SET "set"
#define OPTION "option"
#define NAME "name"
#define REGISTER "register" 
#define UCI_NEW_GAME "ucinewgame"
#define POSITION "position"
#define FEN "fen"
#define MOVES "moves"
#define STARTPOS "startpos"
#define GO "go"
#define SEARCH_MOVES "searchmoves"
#define PONDER "ponder"
#define WTIME "wtime"
#define BTIME "btime"
#define WINC "winc"
#define BINC "binc"
#define MOVES_TO_GO "movestogo"
#define DEPTH "depth"
#define NODES "nodes"
#define MATE "mate"
#define MOVETIME "movetime"
#define INFINITE "infinite"
#define STOP "stop"
#define PONDERHIT "ponderhit"
#define QUIT "quit"

//Engine to GUI commands
#define ID "id name kamilsbot\nid author Kamil\noption name Hash type spin default %d min %d max %d\n"
#define UCIOK "uciok\n"
#define READYOK "readyok\n"
#define BESTMOVE "bestmove"
#define INFO "info"
#define SELDEPTH "seldepth"
#define TIME "time"
#define NODES "nodes"
#define PV "pv"
#define MULTIPV "multipv"
#define SCORE "score"
#define CP "cp" //the score from the engine's point of view in centipawns.
#define MATE "mate"
#define CURRMOVE "currmove"
#define STRING "string"

//Constant values
const int DEFAULT_HASH_SIZE = 1;
const int MIN_HASH_SIZE = 1;
const int MAX_HASH_SIZE = 256;

//Global variables
bool debug_mode = false;

engine* new_engine(bitboard *b) {
    engine *e = malloc(sizeof(engine));
    e->board = b;
    return e;
}

void run(engine *e) {
    char input[1024];
    while (true) {
        scanf("%128s", input);
        if (starts_with(UCI, input)) {
            printf(ID, DEFAULT_HASH_SIZE, MIN_HASH_SIZE, MAX_HASH_SIZE);
            printf(UCIOK);
            fflush(stdout);
        }
    } 
}