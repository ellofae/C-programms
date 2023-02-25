#include <stdio.h>

void line_tostdout(FILE *iop)
{
    register int c;

    while((c = getc(iop)) != '\n')
    {
        putc(c, stdout);
    }
    printf("%c", '\n');
}

void filescompare(FILE *fp1, FILE *fp2)
{
    int c1, c2, index = 0, notEqual = 0;

    while((c1 = getc(fp1)) != EOF && (c2 = getc(fp2)) != EOF)
    {
        if(c1 != c2)
        {
            printf("\nРезультат: файлы не равны начиная с индекса: %d.\n", index);
            printf("Строка, где файлы начинают различаться:\n");
            line_tostdout(fp1);
            notEqual = 1;
            break;
        }
        ++index;
    }
    
    if(!notEqual)
        printf("Результат: файлы равны.\n");
}