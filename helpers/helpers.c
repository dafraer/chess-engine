#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

bool strings_equal(char* str1, char* str2) {
    if (!str1 || !str2 || strlen(str1) != strlen(str2)) return false;
    return strncmp(str1, str2, strlen(str1))==0;
}

bool starts_with(char* prefix, char* string) {
    if (!prefix || !string) return false;
    return strncmp(prefix, string, strlen(prefix))==0;
}

//get_next_cmd reads next token until the space or newline from stdin
//if stdin is empty or read() encounters an error - returns null pointer
char* get_next_cmd() {
    char input[1024];
    if (fgets(input, 1024, stdin)) {
        int len = strlen(input);
        if (!len) return NULL;
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        char *token = malloc(len+1);
        if (!token) return NULL;
        strcpy(token, input);
        return token;
    }
    return NULL;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}