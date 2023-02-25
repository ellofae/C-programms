#include <stdio.h>
#include "functions.h"

/*main function*/
int main(int argc, char *argv[])
{
    int amount = 10;
    while(--argc > 0)
    {
        if((*++argv)[0] == '-' && *++argv[0] == 'n')
        {
            int temp = *++argv[0] - '0';
            if(temp >= 0 && temp < 10)
            {
                amount = temp;
            } else {
                printf("Ошибка, возможный диапозон для -n: 0 - 9\n");
                return -1;
            }
        }
    }

    int nlines = 0;
    while((nlines = reading(lineptr, MAXSIZE)) >= 0)
    {
        printf("Last %d lines:\n", amount);
        writing(lineptr, nlines, amount);
        break;
    }

    return 0;
}
