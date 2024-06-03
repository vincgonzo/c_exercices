#include <stdio.h>

#include "stack.h"


int main(void) {
    Stack sta = new_stack();

    print_stack(sta);

    sta = push_stack(sta, 14);
    sta = push_stack(sta, 178);
    
    print_stack(sta);
    clear_stack(sta);

    print_stack(sta);
    
    return 0;
}