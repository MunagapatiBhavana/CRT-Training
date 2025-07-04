## Connecting Soldiers
To protect people from evil, a long and tall wall was constructed a few years ago. But just a wall is not safe, there should also be soldiers on it, always keeping vigil. The wall is very long and connects the left and the right towers. There are exactly N spots (numbered 1 to N) on the wall for soldiers. The Kth spot is K miles far from the left tower and (N+1-K) miles from the right tower.

Given a permutation of spots P of {1, 2, ..., N}, soldiers occupy the N spots in that order. The P[i]th spot is occupied before the P[i+1]th spot. When a soldier occupies a spot, he is connected to his nearest soldier already placed to his left. If there is no soldier to his left, he is connected to the left tower. The same is the case with right side. A connection between two spots requires a wire of length equal to the distance between the two.

The realm has already purchased a wire of M miles long from Nokia, possibly the wire will be cut into smaller length wires. As we can observe, the total length of the used wire depends on the permutation of the spots P. Help the realm in minimizing the length of the unused wire. If there is not enough wire, output -1.

Input
First line contains an integer T (number of test cases, 1 ≤ T ≤ 10 ). Each of the next T lines contains two integers N M, as explained in the problem statement (1 ≤ N ≤ 30 , 1 ≤ M ≤ 1000).

Output
For each test case, output the minimum length of the unused wire, or -1 if the the wire is not sufficient.

#include <stdio.h>
int f(int n)
{   int x,y;
    if(n == 0)
    return 0;
    if(n & 1)
    {  x=y=n/2;
    }
    else
    {   x=n/2-1;
        y=n/2;
    }
    return n+1+f(x)+f(y);
}
    int main(void)
    {   int n,a,b;
        scanf("%d",&n);
        while(n--)
        {   scanf("%d%d",&a,&b);
            int max,min;
            min=f(a);
            max=a*(a+3)/2;
            if(b<min)
            printf("-1\n");
            else if(b>max)
            printf("%d\n",b-max);
            else
            printf("0\n");
    }
	return 0;
}
INPUT           
4
3 8
3 9
2 4
5 25

OUTPUT 
0
0
-1
5
