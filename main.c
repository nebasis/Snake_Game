//Kbhit-keyboard hit
//rand()-randomly places points

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height = 20, width = 20, x, y,k,ch, fruitX, fruitY,flag,gameEnd,score;//x and y are coordinates of snakes head and fruitXnadY are coordinates of fruit
int tailX[100], tailY[100];
int piece = 0;



void makeLogic()
{
	int i;
	int prevx, prevy, prev2x, prev2y;
	prevx = tailX[0];
	prevy = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	for (i = 1; i < piece;i++)
	{
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevx;
		tailY[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (flag)
	{
		case 1:
		{
			x--;
			break;
		}
		case 2:
		{
			x++;
			break;
		}
		case 3:
		{
			y--;
			break;
		}
		case 4:
		{
			y++;
			break;
		}
	}
	
	/*if (x == 0 || x == height || y == 0 || y = width)
	{
		gameEnd = 1;
	} */
	if (x == fruitX && y == fruitY)
	{
	label3:
		fruitX = rand() % 20;//rand gives random placing and %20 places the fruit in teh box.
		if (fruitX == 0)
			goto label3;//we use this for the condition of fruit being on the edge

	label4:
		fruitY = rand() % 20;//rand gives random placing and %20 places the fruit in teh box.
		if (fruitY == 0)
			goto label4;//we use this for the condition of fruit being on the edge
		score++;
		piece++;
	}
	
}

void input()
{
	if (_kbhit())
	{
		switch (getch())
		{
		case 'w':
		{
			flag = 1;
			break;
		}
		case 's':
		{
			flag = 2;
			break;
		}
		case 'a':
		{
			flag = 3;
			break;
		}
		case 'd':
		{
			flag = 4;
			break;
		}
		}
	}
}


void setup()
{
	x = height / 2;
	y = width / 2;
	label1:
	fruitX = rand()%20;//rand gives random placing and %20 places the fruit in teh box.
	if (fruitX == 0)
		goto label1;//we use this for the condition of fruit being on the edge

    label2:
	fruitY = rand() % 20;//rand gives random placing and %20 places the fruit in teh box.
	if (fruitY == 0)
		goto label2;//we use this for the condition of fruit being on the edge
	gameEnd = 0;
	score = 0;
	piece++;
}


void draw()
{
	system("cls");// alternative of clrscr();
	int i, j;
	for (i = 0; i < height; i++) 
	{
		for (j = 0; j < width; j++)
		{
			if (i == 0 || i == height || j == 0 || j == width)
			{
				printf("*");
			}
			else
			{
				if (i == x && j == y)
				{
					printf("0");
				}
				else if (i == fruitX && j == fruitY)
				{
					printf("@");
				}
				else
				{
					ch = 0;
					for (k == 0; k < piece; k++)
					{
						if (i == tailX[k] && j == tailY[k])
						{
							printf("o");
							ch = 1;
						}
					}
					if (ch == 0)
						printf(" ");
					
				}
				
			}
		}
		printf("\n");
	}
}
int main()
{
	setup();
	while (gameEnd != 1)
	{
		draw();
		input();
		makeLogic();
	}
	
}