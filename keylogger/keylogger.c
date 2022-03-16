#include <stdio.h>
#include <conio.h>

int main()
{
    char ch;
    FILE *fptr;

    fptr = fopen("./log.txt", "w");

    while (1)
    {
        if (kbhit())
        {
            ch = getch();
            int cVal = (int)ch;

            if(cVal - 100 < 0){
                fprintf(fptr, "%c", ' ');
            }

            fprintf(fptr, "%d", cVal);

            if (cVal == 27)
            {
                break;
            } else{
                printf("%d", cVal);
                printf("%c", ' ');
            }
        }
    }
    fclose(fptr);
    return 0;
}