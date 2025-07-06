What is the maximum number of squares of size 2x2 that can be fit in a right angled isosceles triangle of base B.
One side of the square must be parallel to the base of the isosceles triangle.
Base is the shortest side of the triangle


#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	   int x;
	   scanf("%d",&x);
	   printf("%d\n",((x/2)*(x/2)-(x/2))/2);
	}	
	return 0;
}


