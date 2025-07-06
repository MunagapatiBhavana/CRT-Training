The Deadly Sin
Meliodas and Ban are fighting over chocolates. Meliodas has 
X
X chocolates, while Ban has 
Y
Y. Whoever has lesser number of chocolates eats as many chocolates as he has from the other's collection. This eatfest war continues till either they have the same number of chocolates, or atleast one of them is left with no chocolates.
Can you help Elizabeth predict the total no of chocolates they'll be left with at the end of their war?

Input Format
First line will contain 
T
T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, which contains two integers 
X
,
Y
X,Y, the no of chocolates Meliodas and Ban have, respectively.
Output Format
For each testcase, output in a single line the no of chocolates that remain after Ban and Meliodas stop fighting.

#include <stdio.h>

int chocho(int x,int y){
    int m=1,n=1;
    if(x==y) return x+y;
    if(x>y){
        if((x-y)>y && y!=0) n=(x-y)/y;
        
        x-=(n*y);
        chocho(x,y);
        
    
    }
    else{
        if((y-x>x) && x!=0) m=(y-x)/x;
        
        y-=(m*x);
        chocho(x,y);
        
    }
}

int main(void) {
	int t;
	scanf("%d",&t);
    int ans[t];
    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ans[i]=chocho(x,y);
        
    }
    for(int i=0;i<t;i++){
        printf("%d\n",ans[i]);
    }
    // int ans=chocho(5,3);
    // printf("%d",ans);
    

}


