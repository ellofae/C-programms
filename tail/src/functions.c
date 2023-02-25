#include <stdio.h>
#include "functions.h"

/*reading function*/
int reading(char *lineptr[], int max)
{
    int len, nlines;
    char *p, line[MAXLINE];

    len = 0;
    nlines = 0;
    while((len = getline_f(line, MAXLINE)) > 1)
    {
        if(nlines > max || (p = alloc_f(len)) == NULL)
            return -1;
        else {
            strcpy_f(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writing(char *lineptr[], int nlines, int amount)
{
    int i, ind;

    if((ind = nlines - amount) > 0)
    {
        for(i = ind; i < nlines; i++)
            printf("%s\n", *(lineptr + i));
    } else {
        for(i = 0; i < nlines; i++)
            printf("%s\n", *lineptr++);
    }
}

/*getline_f - input line function*/
int getline_f(char *line, int max)
{
    int c, len = 0;
    while((c = getchar()) != EOF && c != '\n' && len < max - 1)
    {
        *(line + len++) = c;
    }
    *(line + len++) = '\0';

    return len;
}

/*strcpy_f - coping function*/
void strcpy_f(char *p, char *t)
{
    while((*p++ = *t++) != '\0')
        ;
}


/*alloc_f - allocating memory function*/
#define ALLOCATIONSIZE 10000
char allocbuf[ALLOCATIONSIZE];
char *allocptr = allocbuf;

char *alloc_f(int len)
{
    if(allocbuf + ALLOCATIONSIZE - allocptr >= len) {
        allocptr += len;
        return allocptr - len;
    } else {
        printf("Ошибка памяти.");
        return NULL;
    }
}
