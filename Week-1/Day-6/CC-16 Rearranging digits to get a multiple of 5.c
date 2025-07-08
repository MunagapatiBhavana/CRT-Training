#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char arr[n];
        int count = 0;
        int i;

        for (i = 0; i <= n; i++)
        {
            scanf("%c", &arr[i]);
        }

        for (int i = 0; i <= n; i++)
        {
            if (arr[i] == '5' || arr[i] == '0')
            {
                count = 1;
                break;
            }
            else
            {
                count = 0;
            }
        }
        if (count == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
