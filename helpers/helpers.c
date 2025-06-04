#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool starts_with(char* prefix, char* string) {
    if (!prefix || !string) return false;
    return strncmp(prefix, string, strlen(prefix))==0;
}