#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int length;
    FILE *fp;
    char *prog = argv[0];

    printf("Type in a word or sentence that you want to find in specified files:\n\n");
    if((length = getline_f(line, MAXLINE)) > 0)
        printf("\nLooking for a word/sentance: %s\n", line);        

    while(--argc > 0)
    {
        if((fp = fopen(*++argv, "r")) == NULL)
        {
            printf("%s: file \'%s\' cannot be opened.\n", prog, *argv);
            exit(1);
        } else {
            file_finder(line, length, fp, *argv);
            fclose(fp);
        }
    }

    exit(0);
}