#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,x1,y1,x2,y2;
	    int d1,d2,min1,min2;
	    scanf("%d %d %d %d %d",&n,&x1,&y1,&x2,&y2);
	    d1=abs(x2-x1)+abs(y2-y1);
	   // printf("\n\n%d\n\n",d1);
	    min1=x1;
	    if(min1>y1)
	    {
	        min1=y1;
	    }
	    if(min1>(n-x1+1))
	    {
	        min1=(n-x1)+1;
	    }
	    if(min1>(n-y1+1))
	    {
	        min1=(n-y1)+1;
	    }
	    
	    min2=x2;
	    if(min2>y2)
	    {
	        min2=y2;
	    }
	    if(min2>(n-x2+1))
	    {
	        min2=(n-x2)+1;
	    }
	    if(min2>(n-y2+1))
	    {
	        min2=(n-y2+1);
	    }
	    d2=min1+min2;
	   // printf("\n\n%d\n\n",d2);

	    if(d1<=d2)
	    {
	        printf("\n%d",d1);
	    }
	    else
	    {
	    printf("\n%d",d2);
	    }
	}
	return 0;
}
