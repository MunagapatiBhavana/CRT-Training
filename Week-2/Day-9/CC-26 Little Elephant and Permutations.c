#include<stdio.h>

int main()
{
    int t;
    // printf("Enter No. of test cases");
    scanf("%d",&t);
//printf("t=%d\n",t);
    while(t--)
    {
     int n;

        scanf("%d",&n);
        int a[n];

        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
//local invesions
int lc=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            ++lc;
        }
        //inversions
        int tc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(a[j]<a[i])
                ++tc;
            }
        }
//        printf("lc=%d tc=%d",lc,tc);
        if(tc==lc)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
