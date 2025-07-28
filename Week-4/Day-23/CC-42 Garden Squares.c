#include <stdio.h>
int main() {
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        char mat[n][m+1];
        for(int j=0;j<n;j++){
            scanf("%s",mat[j]);
        }
        int re=0;
        int val=(n<m)?n:m;
        for(int j=1;j<val;j++){
            for(int n1=0;n1<n;n1++){
                if(n1+j>=n)
                continue;
                for(int m1=0;m1<m;m1++){
                    if(m1+j>=m)continue;
                char a=mat[n1][m1];
                char b=mat[n1+j][m1];
                char c=mat[n1][m1+j];
                char d=mat[n1+j][m1+j];
                if(a==b&&b==c&&c==d)
                re++;
            }
        }
    }
    printf("%d\n",re);
   }
   return 0;
}
