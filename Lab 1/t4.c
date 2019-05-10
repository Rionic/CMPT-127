#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) { 

float i = 0; 
scanf("%f", &i);

if(floor(i)!=0){
printf("%.0f %.0f %.0f\n", floor(i), round(i), ceil(i));
}
else{
printf("scanf error: (%g)\n", i);
}
return 0;}
