#include <stdio.h>

int main(int argc, char **argv){
    char* x = "hey";
    char* fin = argv[1] ?? x;
    printf("%s\n", fin);
    //int* n = NULL;
    //printf("%p", n);
}