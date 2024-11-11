#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Player1Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家1走\n");

	while (1)
	{
		printf("请输入下棋的坐标（行 列）：");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			//下棋
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重输！\a\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\a\n");
		}
	}
}

void Player2Move(char board[ROW][COL], int row, int col, int model)
{
	if (model == 1)
	{
		printf("电脑走\n");

		//判断占用
		while (1)
		{
			int x = rand() % row;
			int y = rand() % col;
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
		}
	}
	else if (model == 2)
	{
		int x = 0;
		int y = 0;
		printf("玩家2走\n");

		while (1)
		{
			printf("请输入下棋的坐标（行 列）：");
			scanf("%d %d", &x, &y);
			//判断坐标合法性
			if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
			{
				//下棋
				//判断坐标是否被占用
				if (board[x - 1][y - 1] == ' ')
				{
					board[x - 1][y - 1] = '#';
					break;
				}
				else
				{
					printf("坐标被占用，请重输！\a\n");
				}
			}
			else
			{
				printf("坐标非法，请重新输入！\a\n");
			}
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;//棋盘没满
		}
	}
	return 1;//棋盘满了
}

int MAX(int row, int col)
{
	if (row > col)
		return row;
	else
		return col;
}

char IsWin(char board[ROW][COL], int row, int col, int Count_Player1, int Count_Player2)
{	
	//判断行
	for (int i = 0; i < row; i++)
	{
		Count_Player1 = 0;
		Count_Player2 = 0;
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
			{
				Count_Player1++;
				Count_Player2 = 0;
				if (Count_Player1 == CHESS_NUM)
					return board[i][j];
			}
			else if (board[i][j] == '#')
			{
				Count_Player2++;
				Count_Player1 = 0;
				if (Count_Player2 == CHESS_NUM)
					return board[i][j];
			}
			else
			{
				Count_Player1 = 0;
				Count_Player2 = 0;
			}
		}
	}

	//判断列
	for (int i = 0; i < col; i++)
	{
		Count_Player1 = 0;
		Count_Player2 = 0;
		for (int j = 0; j < row; j++)
		{
			if (board[j][i] == '*')
			{
				Count_Player1++;
				Count_Player2 = 0;
				if (Count_Player1 == CHESS_NUM)
					return board[j][i];
			}
			else if (board[j][i] == '#')
			{
				Count_Player2++;
				Count_Player1 = 0;
				if (Count_Player2 == CHESS_NUM)
					return board[j][i];
			}
			else
			{
				Count_Player1 = 0;
				Count_Player2 = 0;
			}
		}
	}

	//判断右上到左下斜边
	for (int i = 0; i < MAX(row, col) * 2; i++)
	{
		Count_Player1 = 0;
		Count_Player2 = 0;
		for (int j = 0; j <= i; j++)
		{
			if (board[j][i -j] == '*')
			{
				Count_Player1++;
				Count_Player2 = 0;
				if (Count_Player1 == CHESS_NUM)
					return board[j][i - j];
			}
			else if (board[j][i - j] == '#')
			{
				Count_Player2++;
				Count_Player1 = 0;
				if (Count_Player2 == CHESS_NUM)
					return board[j][i - j];
			}
			else if (board[j][i - j] == ' ')
			{
				Count_Player2 = 0;
				Count_Player1 = 0;
			}
		}
	}

	//判断左上到右下斜边
	for (int i = MAX(row, col) * 2; i >= 0; i--)
	{
		Count_Player1 = 0;
		Count_Player2 = 0;
		for (int j = 0; j <= MAX(row, col) * 2; j++)
		{
			if (board[j][i + j] == '*')
			{
				Count_Player1++;
				Count_Player2 = 0;
				if (Count_Player1 == CHESS_NUM)
					return board[j][i + j];
			}
			else if (board[j][i + j] == '#')
			{
				Count_Player2++;
				Count_Player1 = 0;
				if (Count_Player2 == CHESS_NUM)
					return board[j][i + j];
			}
			else if (board[j][i + j] == ' ')
			{
				Count_Player2 = 0;
				Count_Player1 = 0;
			}
		}
	}

	//判断平局
	 int ret = IsFull(board, row, col);
	 if (ret)
	 {
		 return 'Q';
	 }	 
	 return 'C';
}