#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAXLINE 100
#define MAXSIZE 1000

int getline_f(char *line, int max);
void strcpy_f(char *p, char *t);
int reading(char *lineptr[], int max);
void writing(char *lineptr[], int nlines, int amount);
char *alloc_f(int len);

char *lineptr[MAXSIZE];
#endif