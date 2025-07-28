#include <stdio.h>

int main(void) {
	
	int t;
	scanf("%d",&t);
	while(t--){
	    char a[1001];
	    scanf("%s",&a);
	    int A=1;
	    int B=strlen(a);
	    A+=B;
	    for(int i=1;i<B;i++){
	        int diff=a[i]-a[i-1];
	        if(diff<0)
	        diff+=26;
	        A+=diff;
	    }
	    if(A<=11*B){
	        printf("YES\n");
	    }else{
	        printf("NO\n");
	    }
	    
	}
        return 0;
}
