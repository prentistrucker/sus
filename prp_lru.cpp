//page replacement policy using LRU 
#include <stdio.h>
int main()
{
    int fframe[10], used[10], index, i, l, count, n1, k, nf, np = 0, page[100], tmp, flag = 0, pf = 0;
    printf("Enter no. of frames:");
    scanf("%d", &nf);
    for (i = 0; i < nf; i++)
        fframe[i] = -1;
    printf("Enter total no of pages you want to insert");
    scanf("%d", &np);
    for (i = 0, l = 1; i < np; i++)
    {
        printf("Page No%d: ", l);
        scanf("%d", &page[i]);
    }
    for (count = 0; count < np; count++)
    {
        flag = 0;
        for (n1 = 0; n1 < nf; n1++)
        {
            if (fframe[n1] == page[count])
            {
                printf("\n\t");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (n1 = 0; n1 < nf; n1++)
                used[n1] = 0;
            for (n1 = 0, tmp = count - 1; n1 < nf - 1; n1++, tmp--)
            {
                for (k = 0; k < nf; k++)
                {
                    if (fframe[k] == page[tmp])
                        used[k] = 1;
                }
            }
            for (n1 = 0; n1 < nf; n1++)
                if (used[n1] == 0)
                    index = n1;
            fframe[index] = page[count];
            pf++;
        }
    }
    printf("\nnumber of total page faults is: %d ", pf);
    printf("\n");
    printf("Number of total hits is %d", np - pf);
    printf("\n");
    return 0;
}