#include <stdio.h>
#include <stdlib.h>

#include "../../Constants.h"

int FillArray(int *arr, const int SIZE);
void PrintArray(const int *arr, const int SIZE);

void BubbleSort(int *arr, const int SIZE);

int main()
{
    int arrLITTLE[LITTLE];
    int arrMEDIUM[MEDIUM];
    int arrLARGE[LARGE];

    printf("LITTLE array:\n");
    FillArray(arrLITTLE, LITTLE);
    PrintArray(arrLITTLE, LITTLE);
    printf("\nSORTED LITTLE array:\n");
    BubbleSort(arrLITTLE, LITTLE);
    PrintArray(arrLITTLE, LITTLE);
    printf("\n\n");
    printf("MEDIUM array:\n");
    FillArray(arrMEDIUM, MEDIUM);
    PrintArray(arrMEDIUM, MEDIUM);
    printf("\nSORTED LITTLE array:\n");
    BubbleSort(arrMEDIUM, MEDIUM);
    PrintArray(arrMEDIUM, MEDIUM);
    printf("\n\n");
    printf("LARGE array:\n");
    FillArray(arrLARGE, LARGE);
    PrintArray(arrLARGE, LARGE);
    printf("\nSORTED LITTLE array:\n");
    BubbleSort(arrLARGE, LARGE);
    PrintArray(arrLARGE, LARGE);
    printf("\n\n");
}

int FillArray(int *arr, const int SIZE)
{
    FILE *file;
    if (SIZE == LARGE)
        file = fopen("../../dataLARGE.txt", "r");
    if (SIZE == MEDIUM)
        file = fopen("../../dataMEDIUM.txt", "r");
    if (SIZE == LITTLE)
        file = fopen("../../dataLITTLE.txt", "r");

    if (!file)
        return 1;
    for (int i = 0; i < SIZE; i++)
        fscanf(file, "%d ", &arr[i]);

    fclose(file);
    return 0;
}

void PrintArray(const int *arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
}

void BubbleSort(int *arr, const int SIZE)
{
    int length = SIZE;
    while (length != 0)
    {
        int maxIndex = 0;
        for (int i = 1; i < SIZE; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                maxIndex = i;
            }
        }
        length = maxIndex;
    }
}
