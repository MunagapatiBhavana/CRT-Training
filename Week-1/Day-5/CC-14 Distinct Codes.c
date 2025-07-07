
#include <stdio.h>
#include<string.h>

int main(void) {
	// your code goes here
	int t; scanf("%d",&t);
	while(t--){
	    char s[10001];scanf("%s",s);
	    int l=strlen(s);
	    char c[l-1][3];
	    for(int i=0;i<l-1;i++)
	    {
	        c[i][0]=s[i];
	        c[i][1]=s[i+1];
	        c[i][2]='\0';
	    }
	    int b,a=0;
	    for(int i=0;i<l-2;i++)
	    {
	       if(c[i][1]=='\0')
	       continue;
	       for(int j=i+1;j<l-1;j++){
	       b=strcmp(c[i],c[j]);
	       if(b==0)
	       {
	       a++;
	       c[j][1]='\0';
	       }
	       }
	    }
	    printf("%d\n",l-1-a);
	}
	return 0;
}
