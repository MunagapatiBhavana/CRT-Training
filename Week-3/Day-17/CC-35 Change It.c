#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,count=0;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=0;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    s++;
                }
            }
            if(count<s)
            {
                count=s;
            }
        }
        printf("%d\n",n-count);
    }
    
	// your code goes here
	return 0;
}
