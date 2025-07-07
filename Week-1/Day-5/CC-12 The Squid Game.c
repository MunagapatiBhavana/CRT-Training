#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--){
        int x,sum=0;
        scanf("%d",&x);
        int a[x];
        
        int min;
        for(int i=0;i<x;i++){
            scanf("%d",&a[i]);
        }min=a[0];
        for(int i=0;i<x;i++){
            if(a[i]<min){
                min=a[i];
                
            }sum+=a[i];
        }printf("%d\n",sum-min);
    }
	return 0;
}
