#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char base64_tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char * base64_encode(const unsigned char *input, size_t length){
    int padding = 0;
    size_t output_length = 4 * ((length + 2) / 3);

    char *output = (char*)malloc(output_length + 1);

    if(!output) return NULL;

    int k = 0, w = 0;
    while(k < length){
        unsigned char byte1 = input[k++];
        unsigned char byte2 = (k < length ) ? input[k++] : 0;
        unsigned char byte3 = (k < length ) ? input[k++] : 0;

        output[w++] = base64_tab[(byte1 >> 2) & 0x3F];
        output[w++] = base64_tab[((byte1 << 4) | (byte2 >> 4)) & 0x3F];
        output[w++] = base64_tab[((byte2 << 2) | (byte2 >> 6)) & 0x3F];
        output[w++] = base64_tab[byte3 & 0x3F];
    }

    if(length % 3 == 1){
        output[output_length - 1] = '=';
        output[output_length - 2] = '=';
    }else if (length % 3 == 2){
        output[output_length - 1] = '=';
    }
    output[output_length] = '\0';
    return output;
}

int main(){
    const char * input_str = "Hello World!";
    size_t input_len = strlen(input_str);

    char *encoded = base64_encode((unsigned char*)input_str, input_len);
    printf("Encoded: %s\n", encoded);

    free(encoded);
    return 0;
}
