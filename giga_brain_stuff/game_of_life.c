#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
void print_matrix(int matrix[10][10]);
int sum_neighbors(int matrix[10][10], int i, int j);
int main()
{
    srand(time(NULL));
    int r, state, sum;
    int i, j;
    int matrix[10][10];
    int new_matrix[10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            r = rand() % 2 + 0;
            matrix[i][j] = r;
        }
    }
    while (1)
    {
        Sleep(1000);

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                state = matrix[i][j];
                // if (i == 0 || j == 0 || i == 9 || j == 9)
                // {
                //     new_matrix[i][j] = state;
                // }
                // else
                // {
                sum = sum_neighbors(matrix, i, j);
                if ((sum < 2 || sum > 3) && state == 1)
                {
                    new_matrix[i][j] = 0;
                }
                else if (sum == 3 && state == 0)
                {
                    new_matrix[i][j] = 1;
                }
                else
                {
                    new_matrix[i][j] = state;
                }
                // }
            }
        }

        // print_matrix(matrix);
        system("cls");
        print_matrix(new_matrix);
        memcpy(matrix, new_matrix, sizeof new_matrix);
    }
}

int sum_neighbors(int matrix[10][10], int i, int j)
{
    int x, y, sum;
    sum = 0;
    for (x = -1; x <= 1; x++)
    {
        for (y = -1; y <= 1; y++)
        {
            sum = sum + matrix[(x + i + 10) % 10][(y + j + 10) % 10];
        }
    }
    sum = sum - matrix[i][j];
    return sum;
}

void print_matrix(int matrix[10][10])
{
    int i, j, state;
    for (i = 0; i < 10; i++)
    {
        printf("\n");
        printf("\t");
        for (j = 0; j < 10; j++)
        {
            state = matrix[i][j];
            if (state == 1)
                printf("%s ", "*");
            else
                printf("%s ", " ");
        }
    }
    printf("\n");
}