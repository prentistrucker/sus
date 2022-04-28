// Sequential File Allocation Program in C:
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void recurse(int files[])
{
    int flag = 0, startBlock, len, j, k, ch;
    printf("Enter the starting block and the length of the files: "); // Gather information and memory requirement
    scanf("%d %d", &startBlock ,&len);
    for (j = startBlock; j < (startBlock + len); j++)
    {
        if (files[j] == 0)
            flag++;
    }
    if (len == flag)
    { // Allocate the memory to the file in a sequential manner
        for (int k = startBlock; k < (startBlock + len); k++)
        { // Select any random location from the available location
            if (files[k] == 0)
            {                 // Check if the location that is selected is free or not
                files[k] = 1; // If the location is allocated set the flag = 1
                printf("%d\t%d\n", k, files[k]);
            }
        }
        if (k != (startBlock + len - 1))
            printf("The file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n"); // file not allocated
    printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: "); // Gather information if more files have to be stored
    scanf("%d", &ch);
    if (ch == 1)
        recurse(files);
    else
        exit(0);
    return;
}
int main()
{
    int files[50];
    for (int i = 0; i < 50; i++)
        files[i] = 0;
    printf("Files Allocated are :\n");
    recurse(files); // Print the file number, length, and the block allocated
    getch();
    return 0;
}