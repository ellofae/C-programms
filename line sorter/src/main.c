#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "help_functions.h"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int main() {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort_f(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Ошибка: слишком много строк \n");
        return 1;
    }
}



