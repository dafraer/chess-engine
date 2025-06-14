#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "engine.h"
#include "bitboard/bitboard.h"
#include "helpers/helpers.h"

//GUI to engine commands
#define ON "on"
#define OFF "off"
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
#define SELDEPTH "setdepth"
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

//Returns new instance of an engine
engine* new_engine(bitboard *b) {
    engine *e = malloc(sizeof(engine));
    e->board = b;
    e->hash_size = MIN_HASH_SIZE;
    return e;
}


//Processes setoption command
//Only supports hash option
void process_setoption_cmd(engine *e, char *cmd) {
    char* token = strtok(cmd, " \t");
    token = strtok(NULL, " \t");
    if (token && strings_equal(token, NAME)) token = strtok(NULL, " \t");
    if (token && strings_equal(token, HASH)) token = strtok(NULL, " \t");
    if (token && strings_equal(token, VALUE)) token = strtok(NULL, " \t");
    if (token) e->hash_size = max(atoi(token), MIN_HASH_SIZE);
}

void process_position_cmd(engine *e, char *cmd) {
    setup_pos(e->board, NULL, NULL, NULL, NULL, 0, 1);
}

void process_go_cmd(engine *e, char *cmd) {

}

void process_stop_cmd(engine *e, char *cmd) {
    
}

void process_ponderhit_cmd(engine *e, char *cmd) {

}

void process_debug_cmd(engine *e, char *cmd) {
    char* token = strtok(cmd, " \t");
    token = strtok(NULL, " \t");
    if (token) {
        if (strings_equal("on", token)) {
            debug_mode = true;
        }
        if (strings_equal("off", token)) debug_mode = false;
    }
}

//Processes commands
void process_cmd(engine *e, char *cmd) {
    if (starts_with(UCI_NEW_GAME, cmd)){
        //do nothing *insert chudface*
    } else if (starts_with(UCI, cmd)) {
        printf(ID, DEFAULT_HASH_SIZE, MIN_HASH_SIZE, MAX_HASH_SIZE);
        printf(UCIOK);
        fflush(stdout);
    } else if (starts_with(QUIT, cmd)) {
        exit(0);
    } else if (starts_with(SETOPTION, cmd)) {
        process_setoption_cmd(e, cmd);
    } else if(starts_with(IS_READY, cmd)) {
        printf("readyok\n");
        fflush(stdout);
    } else if (starts_with(POSITION, cmd)) {
        process_position_cmd(e, cmd);
    } else if (starts_with(GO, cmd)) {
        process_go_cmd(e, cmd);
    } else if (starts_with(STOP, cmd)) {
        process_stop_cmd(e, cmd);
    } else if (starts_with(PONDERHIT, cmd)) {
        process_ponderhit_cmd(e, cmd);
    } else if (starts_with(DEBUG, cmd)) {
        process_debug_cmd(e, cmd);
    } 
}

void run(engine *e) { 
    while (true) {
        char *input = get_next_cmd();
        if (!input) continue;
        process_cmd(e, input);
        free(input);
    }   
}

