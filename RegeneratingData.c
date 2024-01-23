

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Constants.h"

void FillDataFILE(const int SIZE);

int main()
{
    srand(time(NULL));
    FillDataFILE(LITTLE);
    FillDataFILE(MEDIUM);
    FillDataFILE(LARGE);

    return 0;
}

void FillDataFILE(const int SIZE)
{
    FILE *file;
    if (SIZE == LARGE)
        file = fopen("dataLARGE.txt", "w");
    if (SIZE == MEDIUM)
        file = fopen("dataMEDIUM.txt", "w");
    if (SIZE == LITTLE)
        file = fopen("dataLITTLE.txt", "w");
    for (int i = 0; i < SIZE; i++)
    {
        fprintf(file, "%d", rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND);
        fprintf(file, " ");
    }
    fclose(file);
}
