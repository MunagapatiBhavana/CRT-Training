#include <stdio.h>

int main(void) {
	int a ,b,c;
	scanf("%d",&a);
	while(a--){
	int count = 0;
	    scanf("%d %d",&b,&c);
	    for(int i=0;i<b;i+=2){
	        for(int j=0;j<c;j+=2){
	            count++;
	        }
	    }
	    printf("%d\n",count);
	}
	return 0;
}
