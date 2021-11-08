#include "../include/Util.h"


char* read_ascii_file(char* _filename) {

    FILE* fp = fopen(_filename, "r");

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* srcBuffer = (char*)malloc(sizeof(char) * size);

    fread(srcBuffer, size, size, fp);

    return srcBuffer;
}
