#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_READ 256

int main() {
    FILE* pt_file = fopen("profil.save", "w+");
    const char text[] = "flag{156986324751248741156329}";

    if(pt_file == NULL)
        exit(1);

    fputs(text, pt_file);

    fclose(pt_file);
    
    rename("profil.save", "data.save");
    // remove("data.save");

    return 0;
}