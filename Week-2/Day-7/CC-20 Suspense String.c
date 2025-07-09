#include <stdio.h>


int main() {
  int t;
  scanf("%d", & t);
  while (t--) {
    int n;
    scanf("%d", & n);
    char arr[n + 1];

    scanf("%s", arr);

    char arr1[3000];
    int k = 0;
    int x=n/2;
    int i = 1501;  
    int j = 1502;
    while (k < x) { //suppose n=6 n/2=3 alice will get 0 1 2 and bob will get 3 4 5                   hence in this case we run loop til n/2 -1
      if (arr[k] == '1') {
        arr1[j] = '1';//suppose n=7 n/2= 3     alice will get 0 1 2 3 and  bob will  get            4 5 6 we still can rull loop till n/2 -1                                            but will have to seperatrly take last turn for alice.
        j = j + 1;
      } else {
        arr1[i] = '0';
        i = i - 1;
      }

      if (arr[n-k-1] == '1') {
        arr1[i] = '1';
        i = i - 1;
      } else {
        arr1[j] = '0';
        j = j + 1;

      }
      k++;
    }
    if (n % 2 == 1) { 
      if (arr[x] == '1') {
        arr1[j ] = '1'; //extra one last turn for alice
        j = j + 1;
      } else {
        arr1[i ] = '0';
        i = i - 1;

      }

    }
    for (int k = i+1; k <= j-1 ; k++) {
      printf("%c", arr1[k]);
    }
    printf("\n");

  }

}
  
