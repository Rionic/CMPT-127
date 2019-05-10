#include <stdio.h>
#include <math.h>

int main(void){
	int values[3];
	int i,a,k,h;
	for(i=0;i<3;i++){
		scanf("%d",&a);
		values[i]=a;
		}
	int x = values[0];
	int z = values[2];
	for(i=0; i>1-values[2];i--){
		int j = values[2]+i-1;
		int left = floor( j * (x/(2.0*z)) );
		int right = ceil( (x-1) + -j * (x/(2.0*z)) ); 
		int dots = values[0] - left*2 -2;
		for(k=0;k<left;k++){
			printf(" ");
		}
		if(i==0){
			printf("#");
			for(h=0;h<dots;h++){
				printf("#");
			}
		}
		else{
			printf("#");
			for(h=0;h<dots;h++){
				printf(".");
			}
		}
		if(values[0]>1){
			printf("#");
			}	
		printf("\n");	
	}
	for(i=0;i<values[0];i++){
		printf("#");
		}
	printf("\n");


}		
