#include <stdio.h>

int main(void){
    int c;
    int max=0;
    int i=0;
    int arr[80];
    while((scanf("%d",&c))!=EOF){
        arr[i]=c;
        i++;
    }

    for(int z=0; z<i; z++){
        if (arr[z]>max)
            max=arr[z];
    }
    int pmax=max;

    for(int x=0; x<pmax; x++){
        for(int y=0; y<i; y++){
            if(arr[y]<max)
                printf(" ");
            else
                printf("#");
        }
        max--;
        printf("\n");
    }

}