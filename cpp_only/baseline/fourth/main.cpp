#include <iostream>
#include <unistd.h>
#include <yara.h>
#include <cstring>    // For strerror()
#include <errno.h>    // For errno

/*
 * DEMO for reading Yara rule files
 */

// function displaying matched rule
int callback(YR_SCAN_CONTEXT* context, int is_running, void* user_data) {
    if (!is_running) {
        // Access the matched rule
        YR_RULES* rules = context->rules; // Get the rule from the scan context
        //std::cout << "Matched rule: " << rule->identifier << std::endl;
    }
    return CALLBACK_CONTINUE;
}

int main() {
    char* cwd = getcwd(NULL, 0);  // Get current working directory
    std::cout << "Current directory: " << cwd << std::endl;
    free(cwd);


    // Initialize YARA library
    if (yr_initialize() != ERROR_SUCCESS) {
        std::cerr << "Failed to initialize YARA" << std::endl;
        return 1;
    }

    // Load the YARA rules from a file
    const char* rule_file = "./example.yara"; // specify the path to your YARA rule file
    YR_RULES* rules = nullptr;

    // Check if the file exists before trying to load it
    if (access(rule_file, F_OK) != 0) {
        std::cerr << "Error: The file " << rule_file << " does not exist or is not accessible." << std::endl;
        return 1;
    }

    int load_result = yr_rules_load(rule_file, &rules);
        if (load_result != ERROR_SUCCESS) {
            // Print the error code returned by YARA
            std::cerr << "Failed to load YARA rules from file: " << rule_file << std::endl;
            std::cerr << "YARA error code: " << load_result << std::endl;

            // Check if it's a system-related error
            if (load_result == ERROR_INVALID_FILE) { //still blockin here...
                std::cerr << "Invalid file format or corrupted YARA rule file." << std::endl;
            } else {
                std::cerr << "An unknown error occurred while loading the rules." << std::endl;
            }
        return 1;
    }

    // Use a simple string to scan, or you can load a file or buffer
    const char* data_to_scan = "This is some test data";

    // Run YARA matching against the data
    if (yr_rules_scan_mem(rules, reinterpret_cast<const uint8_t*>(data_to_scan), strlen(data_to_scan), 0, callback, NULL, 0) != ERROR_SUCCESS) {
        std::cerr << "Error scanning memory" << std::endl;
        return 1;
    }

    // Clean up the YARA library and free resources
    yr_rules_destroy(rules); // Free the rules
    yr_finalize();

    return 0;
}
