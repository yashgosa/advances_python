#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define TRUE 1
#define MAX 20
#define FALSE 0

int matrix[MAX][MAX];
int x, y;
void print_matrix();
int update();
int new_update();

int main()
{
    int flag = FALSE;
    srand(time(NULL));
    extern int matrix[MAX][MAX];
    int ref_matrix[MAX][MAX];
    x = rand() % MAX + 0;
    y = rand() % MAX + 0;

    matrix[x][y] = 1;
    while (TRUE)
    {
        print_matrix();
        flag = new_update();
        if (matrix == ref_matrix)
        {
            break;
        }
        system("cls");
        // Sleep(0.001);
        memcpy(ref_matrix, matrix, sizeof ref_matrix);
    }
    return 0;
}

void print_matrix()
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {

        printf("\n\t");
        // printf("|");
        for (j = 0; j < MAX; j++)
        {
            if (matrix[i][j] == 1)
            {
                // printf("|");
                if (i == x && j == y)
                {
                    printf("@ ");
                }
                else
                    printf("* ");
            }
            else
            {
                printf(" ");
                // printf("|");
            }
        }
    }
}

int update()
{
    int choice = rand() % 4 + 0;
    switch (choice)
    {
    case 0:
        if (x >= MAX - 1)
        {

            x = x - 1;
        }
        else
        {
            x = x + 1;
        }
        break;
    case 1:
        if (x <= 0)
        {
            if (matrix[x + 1][y] == 0)
                x = x + 1;
        }
        else
            x = x - 1;
        break;
    case 2:
        if (y >= MAX - 1)
        {
            if (matrix[x][y - 1] == 0)
                y = y - 1;
        }
        else
            y = y + 1;
        break;
    case 3:
        if (y <= 0)
        {
            if (matrix[x][y + 1] == 0)
                y = y + 1;
        }
        else
            y = y - 1;
        break;
    }
    matrix[x][y] = 1;
}

int new_update()
{
    int vx = rand() % 2 + -1;
    int vy = rand() % 2 + -1;
    x = (x + vx + MAX) % MAX;
    y = (y - vy + MAX) % MAX;

    matrix[x][y] = 1;
}