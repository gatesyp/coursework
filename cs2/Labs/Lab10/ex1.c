// (C) University of San Francisco
// src: https://usfca.instructure.com/courses/1298668/pages/lab-gdb

#include <stdio.h>  
 
int main(int argc, char *argv[])  
{  
        int i, j = 0;  
        for (i = 0; i < 100; i++); /* <-- unwanted semicolon */  
                j += 2;  
        printf("The value of j is: %d\n", j);  
        return 0;  
}
