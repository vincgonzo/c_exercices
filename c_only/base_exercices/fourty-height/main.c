#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_READ 256

int main() {
    FILE* pt_file = fopen("count.txt", "r+");
    int numberRead = 0;
    
    if (pt_file == NULL) {
        // File does not exist, initialize number to 0
        perror("File not found. Initializing number to 0.");

        pt_file = fopen("count.txt", "w+");
        fprintf(pt_file, "%d\n", numberRead);
        fclose(pt_file);
    } else {
        // File exists, read the number from the file
        if (fscanf(pt_file, "%d", &numberRead) != 1) {
            perror("Error reading number from file");
            fclose(pt_file);
            return 1;
        }
        // Close the file after reading
        fclose(pt_file);
    }

    // Increment the number
    numberRead++;

    // Optionally, open the file in write mode to write the incremented number back
    pt_file = fopen("count.txt", "w");
    if (pt_file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write the incremented number back to the file
    fprintf(pt_file, "%d\n", numberRead);

    // Close the file after writing
    fclose(pt_file);

    printf("The incremented number is: %d\n", numberRead);

    return 0;
}