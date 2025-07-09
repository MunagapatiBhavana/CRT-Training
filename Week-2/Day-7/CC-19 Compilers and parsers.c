#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    char a[1000001];
	    scanf("%s",a);
	    int c=0 , result=0;
	    for(int i=0 ; a[i] ; i++){
	        if (a[i]== '<'){
	            c++;
	        }else{
	            c--;
	        }
	        if(c==0){
	            result = i+1;
	        }
	        if(c<0){
	            break;
	        }
	    }printf("%d\n",result);
	}
}
