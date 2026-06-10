#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '.';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(y + i < ROWS && x + j < COLS)
            {
                canvas[y + i][x + j] = '*';
            }
        }
    }
}

void drawLine(int y, int x1, int x2)
{
    int i;

    for(i = x1; i <= x2 && i < COLS; i++)
    {
        canvas[y][i] = '*';
    }
}

void drawTriangle(int x, int y, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(y + i < ROWS && x + j < COLS)
            {
                canvas[y + i][x + j] = '^';
            }
        }
    }
}

void drawCircle(int cx, int cy, int r)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int dx = x - cx;
            int dy = y - cy;

            if(dx * dx + dy * dy <= r * r)
            {
                canvas[y][x] = 'O';
            }
        }
    }
}

void deletePicture()
{
    initCanvas();
    printf("Picture Cleared!\n");
}

void modifyRectangle()
{
    deletePicture();
    drawRectangle(15, 8, 12, 5);

    printf("Rectangle Modified!\n");
}

int main()
{
    int choice;

    initCanvas();

    while(1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Delete Picture\n");
        printf("7. Modify Rectangle\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawRectangle(5, 5, 10, 4);
                printf("Rectangle Drawn!\n");
                break;

            case 2:
                drawLine(2, 5, 25);
                printf("Line Drawn!\n");
                break;

            case 3:
                drawTriangle(25, 5, 5);
                printf("Triangle Drawn!\n");
                break;

            case 4:
                drawCircle(30, 12, 3);
                printf("Circle Drawn!\n");
                break;

            case 5:
                displayCanvas();
                break;

            case 6:
                deletePicture();
                break;

            case 7:
                modifyRectangle();
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
