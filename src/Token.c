#include "../include/Token.h"


void init_tokenlist(tokenlist_t*  tokenlist, size_t size) {
    tokenlist -> tokens = (token_t*)malloc(sizeof(struct __Token) * size);
    tokenlist -> size = size;
    tokenlist -> ptr = 0;
}


void destroy_tokenlist(tokenlist_t* tokenlist) {
    free(tokenlist -> tokens);
    tokenlist -> tokens = NULL;
}


void tokenlist_add(token_t token, tokenlist_t* tokenlist) {
    if (tokenlist -> ptr >= tokenlist -> size) {
        tokenlist -> size *= 2;
        tokenlist -> tokens = (token_t*)realloc(tokenlist -> tokens, sizeof(struct __Token*) * tokenlist -> size);
    }

    tokenlist -> tokens[tokenlist -> ptr] = token;
    ++tokenlist -> ptr;
}


token_t create_token(tokentype_t type, int value, char* string, char character, unsigned int lineNum) {
    token_t token;
    token.type = type;
    token.value = value;
    token.string = string;
    token.character = character;
    token.lineNumber = lineNum;
    return token;
}
