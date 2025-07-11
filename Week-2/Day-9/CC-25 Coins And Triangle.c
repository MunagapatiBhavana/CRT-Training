#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int count=0;
        for(int i=1;i>0;i++){
            n=n-i;
            if(n<0) {
                break;
            }
            count++;
        }
        printf("%d\n",count);
    }
	
	return 0;
}
