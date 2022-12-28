#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size(int monkey, long item_grid[8][30])
{
    int i = 0;

    while (item_grid[monkey][i] != 0)
        i++;
    return i;
}

void add_item(int monkey, long item, long item_grid[8][30])
{
    int i = size(monkey, item_grid);
    item_grid[monkey][i] = item;
}

void new_lev(int monkey, int method[8][3], long *item)
{
    if (method[monkey][0] == 2)
        *item = (*item) * (*item);
    else
        *item = (*item) * method[monkey][1] + method[monkey][2];
    //*item = (*item) / 3;
}

void nul(int m, long item[8][30])
{
    int i = 0;
    while (item[m][i] != 0)
    {
        item[m][i] = 0;
        i++;
    }
}

int safe_number(int cond[8][3])
{
    int num = 1;
    for (int i = 0; i < 8; i++)                   // 8
        num *= cond[i][2];
    return num;
}

int bool(int num)
{
    if (num)
        return 0;
    return 1;
}

int main()
{
    /*long item_grid[8][30] = {{79, 98},
                            {54, 65, 75, 74},
                            {79, 60, 97},
                            {74}};
    int method[8][3] = {{1, 19, 0}, 
                        {1, 1, 6}, 
                        {2, 1, 0}, 
                        {1, 1, 3}};
    int cond[8][3] = {{3, 2, 23},
                      {0, 2, 19},
                      {3, 1, 13},
                      {1, 0, 17}};
    int inspect[8] = {0};*/
    long item_grid[8][30] = {{59, 65, 86, 56, 74, 57, 56},
                            {63, 83, 50, 63, 56},
                            {93, 79, 74, 55},
                            {86, 61, 67, 88, 94, 69, 56, 91},
                            {76, 50, 51},
                            {77, 76}, 
                            {74}, 
                            {86, 85, 52, 86, 91, 95}};
    int method[8][3] = {{1, 17, 0}, 
                        {1, 1, 2}, 
                        {1, 1, 1}, 
                        {1, 1, 7}, 
                        {2, 1, 0},
                        {1, 1, 8}, 
                        {1, 2, 0}, 
                        {1, 1, 6}};
    int cond[8][3] = {{6, 3, 3},
                      {0, 3, 13},
                      {1, 0, 2},
                      {7, 6, 11},
                      {5, 2, 19},
                      {1, 2, 17},
                      {7, 4, 5},
                      {5, 4, 7}};
    int inspect[8] = {0};
    long num = safe_number(cond);
    printf("num = %lu\n", num);
    for (int c = 0; c < 10000; c++)                // cycle
    {
        for (int m = 0; m < 8; m++)             // monkey     // 8
        {
            int i = 0;
            while (item_grid[m][i] != 0)
            {
                long item, boo;
                item_grid[m][i] = item_grid[m][i] % num;
                new_lev(m, method, &item_grid[m][i]);
                item = item_grid[m][i];
                boo = bool(item % cond[m][2]);
                add_item(cond[m][boo], item, item_grid);
                inspect[m] += 1;
                /*for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 30; j++)
                        printf("%d ", item_grid[i][j]);
                    printf("\n");
                }
                printf("\n");*/
                i++;
            }
            //printf("\n");
            nul(m, item_grid);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 30; j++)
            printf("%lu ", item_grid[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 8; i++)
        printf("%d ", inspect[i]);
    printf("\n");
    return 0;
}
