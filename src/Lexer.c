#include "../include/Lexer.h"


void tokenize(tokenlist_t* tl, char* source) {
    typedef unsigned short int bool_t;
    char lex[500];
    unsigned int lexi = 0;
    unsigned int i = 0;
    unsigned int lineNum = 1;

    while (1) {
        memset(lex, 0, 256);
            while (source[i] != '\n' && source[i] != ' ' && source[i] != '\0') {
                lex[lexi] = source[i];

                switch (source[i]) {
                    case '(':
                        tokenlist_add(create_token(T_LPAREN, 0, NULL, '(', lineNum), tl);
                        break;
                    case ')':
                        tokenlist_add(create_token(T_RPAREN, 0, NULL, ')', lineNum), tl);
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        tokenlist_add(create_token(T_INTEGER_LITERAL, 0, NULL, source[i], lineNum), tl);
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                        tokenlist_add(create_token(T_CHAR, 0, NULL, source[i], lineNum), tl);
                        break;
                }

                ++lexi;
                ++i;
            }

            if (source[i] == '\0') {
                break;
            } else if (source[i] == '\n') {
                ++lineNum;
            }

        lexi = 0;
        ++i;
    }
}
