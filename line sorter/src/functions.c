#include <stdio.h>
#include "functions.h"

#define MAXLEN 1000

int getline_f(char*, int);
char *alloc_f(int);
void strcpy_f(char *p, char *line);

/*readlines - reading lines*/
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline_f(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc_f(len)) == NULL)
            return -1; 
        else {
            line[len-1] = '\0'; // removing '\n'
            strcpy_f(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/*writelines - writing lines*/
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/*getline function initialization*/
int getline_f(char *line, int maxlength)
{
    int i, c;
    for (i = 0; i < maxlength-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(line + i) = c;
    
    if (c == '\n') {
        *(line + i) = c;
        ++i;
    }
    *(line + i) = '\0';
    return i;
}

/*strcpy function initialization*/
void strcpy_f(char *p, char *line)
{
    while((*p++ = *line++) != '\0')
        ;
}

/*alloc function initialization*/

#define ALLOCKSIZE 10000

static char allockbuf[ALLOCKSIZE];
static char *allocp = allockbuf;

char *alloc_f(int n)
{
    if(allockbuf + ALLOCKSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return NULL; // or 0
}

