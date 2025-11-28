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

unsigned char* base64_decode(const char *input, size_t *output_length) {
    size_t input_len = strlen(input);
    if (input_len % 4 != 0) {
        return NULL; // Invalid input length
    }

    *output_length = input_len * 3 / 4;
    if (input[input_len - 1] == '=') (*output_length)--;
    if (input[input_len - 2] == '=') (*output_length)--;

    unsigned char *output = (unsigned char*)malloc(*output_length);
    if (!output) return NULL;

    int i = 0, j = 0;
    unsigned char buffer[4];
    while (i < input_len) {
        // Get 4 characters from the input
        for (int k = 0; k < 4; k++) {
            if (i < input_len && input[i] != '=') {
                buffer[k] = strchr(base64_table, input[i]) - base64_table;
            } else {
                buffer[k] = 0;
            }
            i++;
        }

        // Decode the 3 bytes
        output[j++] = (buffer[0] << 2) | (buffer[1] >> 4);
        if (j < *output_length) {
            output[j++] = (buffer[1] << 4) | (buffer[2] >> 2);
        }
        if (j < *output_length) {
            output[j++] = (buffer[2] << 6) | buffer[3];
        }
    }

    return output;
}

int main(){
    const char * input_str = "Hello World!";
    size_t input_len = strlen(input_str);

    char *encoded = base64_encode((unsigned char*)input_str, input_len);
    printf("Encoded: %s\n", encoded);

    free(encoded);

    const char *encoded_str = "SGVsbG8sIFdvcmxkIQ==";
    size_t decoded_len;

    unsigned char *decoded = base64_decode(encoded_str, &decoded_len);
    if (decoded) {
        printf("Decoded: ");
        for (size_t i = 0; i < decoded_len; i++) {
            putchar(decoded[i]);
        }
        putchar('\n');
        free(decoded);
    } else {
        printf("Error decoding\n");
    }

    return 0;
}
