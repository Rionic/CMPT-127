#include <stdio.h>
int main(void){
int i;
while ( fscanf(stdin, "%d", &i) == 1 )
{
while(i-- > 0){
printf("#");
}
printf("\n");
}
return 0;
}
