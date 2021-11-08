#include "../include/Parser.h"


ast parse(tokenlist_t tokens) {
    typedef unsigned short int bool_t;
    ast __ast;
    __ast.tree_size = 20;
    __ast.nodes = (astnode_t*)malloc(sizeof(struct __AST_NODE) * __ast.tree_size);
    bool_t end_statement = 0;
    token_t last_token;  /* For initial check. */

    for (int i = 0; i < tokens.size; ++i) {
        last_token = tokens.tokens[i];
        printf("%c\n", tokens.tokens[i].character);
        if (tokens.tokens[i].type == T_END_STATEMENT) {
            end_statement = 1;
        }
    }

    if (!(end_statement)) {
        printf("ERROR: Missing semicolon on line %d.", last_token.lineNumber);
    }

    for (int i = 0; i < tokens.size; ++i) {
        switch (tokens.tokens[i].type) {
            case T_LPAREN:

        }
    }

    return __ast;
}
