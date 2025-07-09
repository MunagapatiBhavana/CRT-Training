#include <stdio.h>

int main(void) {
	int n;
	scanf("%d",&n);
	while(n--)
	{
	    char s[400],temp[400];
	    int top=-1,a=0;
	    scanf("%s",&s);
	    for(int i=0;i<strlen(s);i++){
	        if (s[i]=='*' || s[i]=='+' || s[i]=='-'||s[i]=='^'||s[i]=='('||s[i]=='/')
	        temp[++top]=s[i];
	        else if(top!=-1 && s[i]==')'){
	            while(temp[top]!='('){
	                printf("%c",temp[top--]);
	                
	            }
	            if(temp[top]=='(')top--;
	  	        }
	  	        else printf("%c",s[i]);
	    }
	    printf("\n");
	    
	}
	return 0;
}
