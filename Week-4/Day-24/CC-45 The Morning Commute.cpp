#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while (t--)
	{
	  int n;
	  cin>>n;
	  ll tym=0;
	   for (int i = 0; i < n; i++)
	   {
        int x,l,f;
        cin >> x>>l>>f;
        if (tym<x)
        {
            tym=x+l;
        }
        else if (tym==x)
        {
            tym+=l;
        }
        else 
        {
            if (tym>x && tym<=(x+f))
            {
                tym = x+l+f;
            }
            else if (tym>x && tym>(x+f)) 
            {
               int d=tym-x;
               d=d/f;
               if(x+d*f==tym)
               {
                   tym+=l;
               }
               else
               {
                  tym=x+((d+1)*f)+l; 
               }
            }
        }
    }
    cout << tym<<"\n";
  }
}


