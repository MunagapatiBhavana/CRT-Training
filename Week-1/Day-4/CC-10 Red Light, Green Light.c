#include <stdio.h>

int main(void) {
	int t,n,k,i,death=0;
	scanf("%d",&t);
	while(t!=0)
	{scanf("%d %d",&n,&k);
	int ppl[n];
	for(i=0;i<n;++i)
	{
	    scanf("%d",&ppl[i]);
	    if(ppl[i]>k)
	    ++death;
	}
	printf("%d\n",death);
	death=0;
	    --t;
	}
	return 0;
}

