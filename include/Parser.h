#ifndef KESS_PARSER_H_
#define KESS_PARSER_H_

#include "../include/Token.h"
#include <stdlib.h>
#include <stdio.h>


typedef enum __AST_TYPES {
    INTEGER_LITERAL,
    CALL_EXPRESSION,
} ast_types;


typedef enum ParseStatus {
    PARSE_SUCCESS,
    SYNTAX_ERROR,
} parse_status;


typedef struct __AST_NODE {
    ast_types type;
    char* name;
    char* params[250];
} astnode_t;


typedef struct __AST {
    char* type;
    size_t tree_size;
    astnode_t* nodes;
    parse_status __parse_status;
} ast;


ast parse(tokenlist_t tokens);


#endif  // KESS_PARSER_H_
