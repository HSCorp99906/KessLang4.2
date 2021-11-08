#include "../include/Parser.h"


ast parse(tokenlist_t tokens) {
    typedef unsigned short int bool_t;
    ast __ast;
    __ast.__parse_status = PARSE_SUCCESS;
    __ast.tree_size = 20;
    __ast.nodes = (astnode_t*)malloc(sizeof(struct __AST_NODE) * __ast.tree_size);
    bool_t semicolon_found = 0;
    token_t lastToken;

    unsigned int lparenCount = 0;
    unsigned int rparenCount = 0;

    for (int i = 0; i < tokens.size; ++i) {
        lastToken = tokens.tokens[i];
        if (tokens.tokens[i].type == T_END_STATEMENT) {
            semicolon_found = 1;
        } else if (tokens.tokens[i].type == T_LPAREN) {
            ++lparenCount;
        } else if (tokens.tokens[i].type == T_RPAREN) {
            ++rparenCount;
        }

        if (tokens.tokens[i].type == T_NEWLINE) {
            if (!(semicolon_found)) {
                __ast.__parse_status = SYNTAX_ERROR;
                printf("ERROR: Missing semicolon on line %d.\n", lastToken.lineNumber);
            } else if (lparenCount != rparenCount) {
                __ast.__parse_status = SYNTAX_ERROR;
                printf("ERROR: Unmatched parenthesis on line %d.\n", lastToken.lineNumber);
            }

            /* <== Begin Reset ==> */
            semicolon_found = 0;
            lparenCount = 0;
            rparenCount = 0;
            /* <== End Reset ==> */
        }
    }


    return __ast;
}
