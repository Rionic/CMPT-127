#include <stdio.h>
#include <math.h>

int main(void)
{ 
float i = 0; 
while(scanf("%f", &i)!=EOF)
{
printf("%.0f %.0f %.0f\n", floor(i), round(i), ceil(i));
}
if(scanf("%f",&i)==EOF)
{
printf("Done.\n");
}
return 0;
}

