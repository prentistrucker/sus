//page replacement policy using fifo 
#include <stdio.h>
int main()
{
    int i, j, n, a[50], frame[10], no, k, flag = 0, fault = 0, hit = 0;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);
    printf("\n ENTER THE PAGE NUMBER :\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
    {
        frame[i] = -1;
    }
    j = 0;
    for (i = 1; i <= n; i++)
    {
        flag = 0;
        for (k = 0; k < no; k++)
        {
            if (frame[k] == a[i])
            {
                flag = 1;
                hit++;
            }
        }
        if (flag == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            fault++;
        }
    }
    printf("Page Fault Is %d \n", fault);
    printf("Page hit is %d \n", hit);
    return 0;
}