#include <stdio.h>

int main(void) {
   
    int t,n,a[100000]={0},i;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&t);
            a[t]++;
        }
        for(i=0;i<n+1;i++)
        {
            if(a[i]==0)
            {
               printf("%d ",i);
            }
    }
    return 0;
}
