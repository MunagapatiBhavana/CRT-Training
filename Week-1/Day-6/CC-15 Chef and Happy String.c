#include<stdio.h>
int main()
{
    int n,i,t,c=0;
    scanf("%d",&t);
    for(n=0;n<t;n++)
    {
        c=0;
        char s[1000];

        scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
        {
            if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')&&
               (s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u')&&
                (s[i+2]=='a'||s[i+2]=='e'||s[i+2]=='i'||s[i+2]=='o'||s[i+2]=='u'))
                c++;
        }
        if(c!=0)
            printf("happy");
        else
            printf("sad");
    printf("\n");
    }
}
