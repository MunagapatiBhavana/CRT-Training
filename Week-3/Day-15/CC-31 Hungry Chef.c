#include <stdio.h>
int main(void) {
    int n,i,a,b,c,d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    { int flag=0;
     scanf("%d%d%d%d",&a,&b,&c,&d);
      if(d/b>=c) printf("0 %d\n",c);
      else if(d/a<c) printf("-1\n");
      else
      {
          int k=(d-(b*c))/(a-b);
          if((d-(b*c))%(a-b)!=0) k++;
          printf("%d %d\n",k,c-k);
      }
      
    }
	return 0;
}
