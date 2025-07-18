#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char s[n+1];
        scanf("%s",s);int c=0,m=0,flag=1;
        for(int i=0;i<n;i++){
            if(s[i]=='1')c++;
            else m++;
            if(c>=m){
                flag=0;
                break;
            }
        }
        if(!flag)
        printf("YES\n");
        else printf("NO\n");
        
    }
}
