#include <stdio.h>
#include "help_functions.h"

/*qsort_f - sotring lines*/
void qsort_f(char *lineptr[], int left, int right)
{
    int i, last;

    if(left >= right)
        return;
    
    swap_f(lineptr, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(strcmp_f(lineptr[i], lineptr[left]) < 0)
            swap_f(lineptr, ++last, i);
    swap_f(lineptr, left, last);
    qsort_f(lineptr, left, last - 1);
    qsort_f(lineptr, last + 1, right);
}

/*swap - swapping*/
void swap_f(char *lineptr[], int i, int j)
{
    char *temp;

    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}

/*strcmp - comparing two arrays*/
int strcmp_f(char *s, char *t)
{
    for(; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}
