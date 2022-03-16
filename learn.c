#include <stdio.h>
#include <conio.h>

int main()
{
    char ch;
    while (1) {
  
        if ( kbhit() ) {
  
            // Stores the pressed key in ch
            ch = getch();
  
            // Terminates the loop
            // when escape is pressed
            if ((int)ch == 27)
                break;
            else
                printf("%d", ch);
  
        }
    }
    return 0;
}

void temp()
{
    int a = 320;
    char *ptr;
    ptr = (char *)&a;
    printf("%d", *ptr);
    printf("%d", &a);
}