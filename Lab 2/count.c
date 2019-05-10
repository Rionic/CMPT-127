#include <ctype.h>
#include <stdio.h>

 int main(void) {
    unsigned long int charcount = 0;
    unsigned long int wordcount = 0;
    unsigned long int linecount = 0;
    int c;
    int x=0;

    while ((c = getchar()) != EOF) {
            charcount++;

        if ((isalpha(c)==0) && c!='\'') {
            x++;
        }
        else{
            x=0;
        }

        if ((isalpha(c)==0) && (c!='\'') && (x<2))  {
            wordcount++;
        }
        if (c == '\n') {
            linecount++;
        }
    }

    printf("%lu %lu %lu\n", charcount, wordcount, linecount);
    return 0;
}