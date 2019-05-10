#include <stdio.h>
	int i;

	int identical( int a[], int b[], unsigned int len ){
		int flag=1;
		for (i=0;i<len;i++){
			if(a[i]!=b[i]){
				flag=0;
			}
		}
		return flag;
	}