#include <stdio.h>

int getline_f(char *line, int max)
{
    int c, len;
    char *ptr = line;

    len = 0;
    while((c = getchar()) != EOF && len <= max - 1)
    {
        *ptr++ = c;
        ++len;
    }
    *ptr = '\0';

    return len;
}

void file_finder(char *line, int len, FILE *fp, char *name)
{
    int c, index, counter;
    
    index = 0;
    counter = 0;
    while((c = getc(fp)) != EOF)
    {
        ++counter;
        if(c == line[index++])
        {
            if(index == len)
            {
                printf("Word/sentance \'%s\' found in file \'%s\' at index: %d\n", line, name, counter);
                break;
            }
        } else {
                index = 0;
        }
    }
}