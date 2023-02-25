#include <stdio.h>
#include <string.h>

#define MAX 100

int expand(char s1[], char s2[]);

int main() {
    char s1[MAX];
    char s2[MAX];
    int c, i;

    c = i = 0;
    while((c = getchar()) != EOF) {
        s1[i++] = c;
    }
    s1[i] = '\0';
    
    printf("\nfirst: %s\n\n", s1);

    c = i = 0;
    while((c = getchar()) != EOF) {
        s2[i++] = c;
    }
    s2[i] = '\0';

    printf("\nsecond: %s\n\n", s2);

    expand(s1, s2);

    return 0;
}

int expand(char s1[], char s2[]) {
    int i, j, iterm;
    char a, b;
    int ind1, ind2, e;

    char s3[MAX];

    ind1 = ind2 = e = iterm = 0;
    for(i = 0; i < strlen(s1); i++) {
        if(s1[i] == '-')
        {
            a = s1[i-1];
            b = s1[i+1];

            for(j = ind1; j < strlen(s2); j++)
            {
                if(s2[j] == a && j > e)
                {
                    ind1 = j;
                    e = j;
                }
                else if (s2[j] == b && j > e)
                {
                    ind2 = j;
                    e = 0;
                }

                if(ind2 - ind1 > 0)
                {
                    break;
                }
            }

            printf("\nind1: %d,  ind2: %d\n", ind1, ind2);

            if(ind1 < ind2)
            {
                int exp = ind2 - ind1;
                int k;

                for(k = 0; k <= exp; k++)
                {
                    s3[i + iterm - 1 + k] = s2[ind1 + k];
                }
                
                iterm = iterm + exp - 2; // -2
                ind2 = 0;
                
            }
        }
        else {
            s3[i + iterm] = s1[i];
        }
    }
    s3[i + iterm] = '\0';
    printf("\nfinal: %s\n", s3);
}