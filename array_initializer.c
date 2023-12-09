#include "shell.h"
#include <stdio.h>

/**
 * main- Entry point
 *
 * Return:0(success)
 */
int main() {
    char input[] = "This,is,a,sample,string";
    const char delimiters[] = ",";

    // Tokenize the input string using the custom implementation of strtok
    char *token = str_tok(input, delimiters);
    
    // Print the tokens
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = str_tok(NULL, delimiters);
    }

    return (0);
}
