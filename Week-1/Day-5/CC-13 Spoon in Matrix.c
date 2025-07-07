#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,m;
	     scanf("%d%d",&n,&m);
	    char mat[150][150];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%s",mat[i]);
	    }
	    int f=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m-4;j++)
	        {
	            if(tolower(mat[i][j])=='s' && tolower(mat[i][j+1])=='p'&&tolower(mat[i][j+2])=='o'&&tolower(mat[i][j+3])=='o'&&tolower(mat[i][j+4])=='n')
	            {
	                f=1;
	                break;
	            }
	        }
	    }
	    if(!f)
	    {
	        for(int i=0;i<m;i++)
	        {
	            for(int j=0;j<n-4;j++)
	            {
	                if(tolower(mat[j][i])=='s' &&tolower(mat[j+1][i])=='p' &&tolower(mat[j+2][i])=='o' &&tolower(mat[j+3][i])=='o' &&tolower(mat[j+4][i])=='n') 
	                {
	                    f=1;
	                    break;
	                }
	            }
	        }
	    }
	    if(f)
	    {
	        printf("There is a spoon!\n");
	    }
	    else
	    {
	        printf("There is indeed no spoon!\n");
	    }
	}

}

