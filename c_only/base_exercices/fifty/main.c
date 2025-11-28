#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

// Function to print the SHA-256 hash in hexadecimal format
void print_sha256(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    // The string to be hashed
    const char *string = "Hello, world!";
    
    // Buffer to hold the SHA-256 hash
    unsigned char hash[SHA256_DIGEST_LENGTH];
    
    // Compute the SHA-256 hash
    SHA256((unsigned char*)string, strlen(string), hash);
    
    // Print the SHA-256 hash
    printf("SHA-256 hash of '%s': ", string);
    print_sha256(hash);
    
    return 0;
}