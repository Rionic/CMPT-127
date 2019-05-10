#include <stdio.h>
void reverse( int arr[], unsigned int len ){
	int temp;
	for(int i=0;i<len/2;i++){
		temp=arr[len-1-i];
		arr[len-1-i]=arr[i];
		arr[i]=temp;
	}
}
