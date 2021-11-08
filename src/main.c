#include <stdlib.h>
#include "../include/Util.h"
#include "../include/Lexer.h"
#include "../include/Token.h"
#include "../include/Parser.h"


int main(int argc, char* argv[]) {
    char* source = read_ascii_file(argv[1]);

    tokenlist_t tokenlist;
    init_tokenlist(&tokenlist, 10);
    tokenize(&tokenlist, source);
    ast __ast = parse(tokenlist);

    destroy_tokenlist(&tokenlist);
    free(source);
    free(__ast.nodes);
}
