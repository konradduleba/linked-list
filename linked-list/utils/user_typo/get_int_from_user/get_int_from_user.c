#include <stdio.h>

#include "get_int_from_user.h"
#include "string.h"

int getIntFromUser(string message){
    int number;
    
    printf("%s", message);
    
    while(scanf("%d", &number) != 1)
    {
        printf("%s", message);
        while(getchar() != '\n');
    }
    
    return number;
}
