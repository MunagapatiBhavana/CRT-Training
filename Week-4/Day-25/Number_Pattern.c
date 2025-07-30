#include <stdio.h>

int main()
{
    int n,i,j,cur,f;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(j==0){
                cur=i+1;
                f=0;
            }
            else if(j%2==0){
                f=2*(i-j+1);
            }
            else{
                f=2*(n-i-1)+1;
                
            }
            int nxt=cur+f;
            printf("%d  ",nxt);
            cur=nxt;
        }
        printf("\n");
    }
  

    return 0;
}

Output:
1       
2       9                 
3       8      10            
4       7      11     14     
5       6      12     13    15
