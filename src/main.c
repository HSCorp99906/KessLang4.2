#include <stdlib.h>
#include "../include/Util.h"
#include "../include/Lexer.h"
#include "../include/Token.h"


int main(int argc, char* argv[]) {
    char* source = read_ascii_file(argv[1]);

    tokenlist_t tokenlist;
    init_tokenlist(&tokenlist, 10);
    destroy_tokenlist(&tokenlist);

    free(source);
}
