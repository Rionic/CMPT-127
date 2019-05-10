#include <stdio.h>

int main(void){
int i,a,k,j,h,g;
int values[3];

for(i=0;i<3;i++){
scanf("%d",&a);
values[i]=a;
}

for(k=0;k<values[0];k++){
printf("#");
}
printf("\n");
for(h=0;h<values[1]-2;h++){
printf("#");
for(g=0;g<values[0]-2;g++){
printf(".");
}
if(values[0]>1){
printf("#");
}
printf("\n");
}
if(values[1]>1){
for(j=0;j<values[0];j++){
printf("#");
}

printf("\n");
}
return 0;
}
