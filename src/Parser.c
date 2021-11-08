#include "../include/Parser.h"


ast parse(tokenlist_t tokens) {
    ast __ast;
    __ast.tree_size = 20;
    __ast.nodes = (astnode_t*)malloc(sizeof(struct __AST_NODE) * __ast.tree_size);

    for (int i = 0; i < tokens.size; ++i) {
        switch (tokens.tokens[i].type) {
            case T_LPAREN:

        }
    }

    return __ast;
}
