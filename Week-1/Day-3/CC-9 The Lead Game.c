The Lead Game
The game of billiards involves two players knocking 3 balls around on a green baize table. Well, there is more to it, but for our purposes this is sufficient.

The game consists of several rounds and in each round both players obtain a score, based on how well they played. Once all the rounds have been played, the total score of each player is determined by adding up the scores in all the rounds and the player with the higher total score is declared the winner.

The Siruseri Sports Club organises an annual billiards game where the top two players of Siruseri play against each other. The Manager of Siruseri Sports Club decided to add his own twist to the game by changing the rules for determining the winner. In his version, at the end of each round, the cumulative score for each player is calculated, and the leader and her current lead are found. Once all the rounds are over the player who had the maximum lead at the end of any round in the game is declared the winner.

#include <stdio.h>
int main(void) {
	int n,i;
    scanf("%d",&n);
    int a[n],b[n],lead[n],win[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    int sum1=0,sum2=0;
    for(i=0;i<n;i++)
    {
        sum1+=a[i];
        sum2+=b[i];
        if(sum1>sum2)
        {
            lead[i]=sum1-sum2;
            win[i]=1;
        }
        else{
            lead[i]=sum2-sum1;
            win[i]=2;
        }
 }
  int w=0,l=0;
 for(i=0;i<n;i++){
  if(l<=lead[i])
  {
   l=lead[i];
   w=win[i];
  }
 }
 printf("%d %d",w,l);
	return 0;
}

