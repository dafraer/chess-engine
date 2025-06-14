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

//get_next_token reads next token until the space or newline from stdin
//if stdin is empty or read() encounters an error - returns null pointer
char* get_next_token() {
    char input[128];
    int num_read = scanf("%127s", input);
    if (num_read > 0) {
        char *token = malloc(sizeof(char)*(strlen(input)+1));
        if (!token) return NULL;
        strcpy(token, input);
        return token;
    }
    return NULL;
}