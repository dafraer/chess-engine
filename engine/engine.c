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
#define SETOPTION "setoption"
#define VALUE "value"
#define HASH "Hash"
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
    e->hash_size = MIN_HASH_SIZE;
    return e;
}

void process_command(engine *e, char *input) {
    if (strings_equal(UCI, input)) {
        printf(ID, DEFAULT_HASH_SIZE, MIN_HASH_SIZE, MAX_HASH_SIZE);
        printf(UCIOK);
        fflush(stdout);
    } else if (strings_equal(QUIT, input)) {
        exit(0);
    } else if (strings_equal(SETOPTION, input)) {
        char *next_input = get_next_token();
        if (strings_equal(NAME, input)) process_command(e, next_input);
        free(next_input);    
    } else if(strings_equal(IS_READY, input)) {
        printf("readyok\n");
        fflush(stdout);
    } else if(strings_equal(NAME, input)) {
        char *next_input = get_next_token();
        if (strings_equal(HASH, input)) process_command(e, next_input);
        free(next_input);
    } else if (strings_equal(HASH, input)) {
        char *next_input = get_next_token();
        if (strings_equal(VALUE, next_input)) process_command(e, next_input);
        free(next_input);
    } else if (strings_equal(VALUE, input)) {
        int mb;
        scanf("%d", &mb);
        printf("%d\n", mb);
        e->hash_size = mb; 
    }
}

void run(engine *e) { 
    while (true) {
        char *input = get_next_token();
        if (!input) continue;
        process_command(e, input);
        free(input);
    } 
}

