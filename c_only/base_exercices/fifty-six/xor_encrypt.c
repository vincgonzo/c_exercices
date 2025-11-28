#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
   
void die(char const *fmt, ...){
    va_list args;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    exit(1);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *inFile, *outFile;
    unsigned char *key, *buff;
    size_t k, w, z;

    // Treatment of opening & copy content of file
    if(argc != 4)
        die("Usage: %s <in file> <out file> <key>\n", argv[0]);

    inFile = argv[1];
    outFile = argv[2];
    key = (unsigned char*) argv[3];

    file = fopen(inFile, "rb");
    if(!file) die("Failed to open file '%s'\n", inFile);

    fseek(file, 0, SEEK_END);
    z = ftell(file);
    fseek(file, 0, SEEK_SET);

    buff = malloc(z);
    if(!buff) die("Out of memory\n");

    if(fread(buff, 1, z, file) != z)
        die("Failed to read file '%s'\n", inFile);
    fclose(file);
 
    // XOR content & write into new output file
    w = 0;
    for(k = 0; k < z; k++){
        buff[k] ^= key[w];
        w = (w+1) % strlen(key);
    }

    file = fopen(outFile, "wb");
    if(!file) die("Failed to open file '%s'\n", outFile);

    if(fwrite(buff, 1, z, file) != z)
        die("Failed to write file '%s'\n", outFile);
    fclose(file);

    return 0;
}
