#include <stdio.h>
#include<string.h>

int main() {
	// your code goes here
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    char S[6], T[6], M[6];
	    scanf("%s",S);
	    scanf("%s",T);
	    for(int i=0;i<5;i++)
	    {
	    	if(S[i]==T[i])
                M[i]='G';
            else
            
                M[i]='B';
            
	    }
         M[5]='\0';
         printf("%s\n",M);
    	
	}
	
         return 0;
}




