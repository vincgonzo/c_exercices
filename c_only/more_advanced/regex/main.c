#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <inttypes.h>

#define NUM_MATCHES 3

int main(int argc, char **argv){

    regex_t re;
    regmatch_t match[NUM_MATCHES];

    if (argc != 2){
        printf("usage: %s <string_to_match>\n", argv[0]);
        return EXIT_FAILURE;
    }

    //key=value
    //name=test

    const char *pattern = "^([a-zA-Z]+)=([a-zA-Z0-9_]+)$";

    //COMPILE REGEX
    if(regcomp(&re, pattern, REG_EXTENDED)){
        perror("regex compile failed");
        return EXIT_FAILURE;
    }

    //exec
    int result_reg = regexec(&re, argv[1], NUM_MATCHES, match, 0);

    if(!result_reg){
        printf("Match!");
        for(int i=0; i < NUM_MATCHES; i++){
            printf("match[%d]: %.*s (%d -- %d)\n", //possible type mismatch with PRIdREGOFF_T return type
                i, 
                (int)(match[i].rm_eo - match[i].rm_so), //end offset minus begin offset to get bytes length
                argv[1] + match[i].rm_so,
                match[i].rm_so,
                match[i].rm_eo
            );
        }
    }else if(result_reg == REG_NOMATCH){
        printf("No Match!");
    }else{
        perror("regexec failed!");
        return EXIT_FAILURE;
    }

    //cleanup
    regfree(&re); 

    return EXIT_SUCCESS;
}