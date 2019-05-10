#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REPLACEMENT "CENSORED"
#define BUFFER_SIZE (1024)

int main(int argc, char *argv[]){
    ssize_t br;
    char *s, *line = malloc(BUFFER_SIZE);
    size_t nbytes = BUFFER_SIZE, replacement_length = strlen(REPLACEMENT);

    while ((br = getline(&line, &nbytes, stdin)) != -1){  
        for (int i = 1; i < argc; i++){
            while ((s = strstr(line, argv[i])) != NULL){
                size_t search_length = strlen(argv[i]);
                size_t tail_length = strlen(s + search_length);
                (void) memmove(s + replacement_length, s + search_length, tail_length + 1);
                (void) memcpy(s, REPLACEMENT, replacement_length);
            }
        }
        (void) fputs(line, stdout);
    }
    free(line);
}



















/*#include <ctype.h>
#include <stdio.h>
#include <string.h>


int wordchecker(int result){
	unsigned long int wordcount,x;

	if ((isalpha(result)==0) && result!='\'') {
            x++;
        }
        else{
            x=0;
        }

        if ((isalpha(result)==0) && (result!='\'') && (x<2))  {
            wordcount++;
		}
}

//argc is the number of words entered INCLUDING ./a.out
// argv[] is an array of words argv[0] = ./a.out, argv[0][0]=. 
int main(int argc, char* argv[]){
	int c;
	int counter,x,j=0;
	int i=1;
	int wordcount;
	int arr[10000];

	while (c != EOF){
		c = fgetc(stdin);
		if (c==EOF)
			break;
     	for(i=1;i<argc;i++){
     		for (j=0;j<strlen(argv[i]);j++){
     			if(argv[i][j]!=c){
     				counter=0;
     				break;
     			}
     			else{
     				arr
     				printf("%c\n",c);
     				counter=1;
     			}


     			}
     		}
	}

}*/