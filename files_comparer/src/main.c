#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    int count = 0;

    char *prog = argv[0];
    if(argc == 1)
    {
        fprintf(stderr, "%s: не указаны файлы сравнения.\n", prog);
        exit(1);
    }
    else {
        while(--argc > 0) {
            /**/
            if(count == 0) {
                if((fp1 = fopen(*++argv, "r")) == NULL)
                {
                    fprintf(stderr, "%s: не может быть открыт файл - %s.\n", prog, *argv);
                    exit(2);
                }
                printf("File №1: %s\n", *argv);
                ++count;
            }
            else if(count == 1) {
                if((fp2 = fopen(*++argv, "r")) == NULL)
                {
                    fprintf(stderr, "%s: не может быть открыт файл - %s.\n", prog, *argv);
                    exit(2);
                }
                printf("File №2: %s\n", *argv);
                ++count;
            } else {
                fprintf(stderr, "%s: должно быть указано два файла.\n", prog);
                exit(3);
            }
            /**/
        }
    }
    
    filescompare(fp1, fp2);
    // fclose(fp1); // необязательно, т.к. присутствует exit
    // fclose(fp2); // необязательно, т.к. присутствует exit 

    exit(0);
}