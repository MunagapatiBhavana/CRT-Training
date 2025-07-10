#include <stdio.h>
int main(void) {
	// your code goes here
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int k,r=0,temp=0;
	    k=n;
	    while(n!=0)
	    {
	        temp=n%10;
	        r=r*10+temp;
	        n=n/10;
	    }
    	if(k == r)
        printf("wins\n");
    	else
    	printf("loses\n");
	}
	return 0;
}
