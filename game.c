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
	printf("���1��\n");

	while (1)
	{
		printf("��������������꣨�� �У���");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			//����
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã������䣡\a\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\a\n");
		}
	}
}

void Player2Move(char board[ROW][COL], int row, int col, int model)
{
	if (model == 1)
	{
		printf("������\n");

		//�ж�ռ��
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
		printf("���2��\n");

		while (1)
		{
			printf("��������������꣨�� �У���");
			scanf("%d %d", &x, &y);
			//�ж�����Ϸ���
			if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
			{
				//����
				//�ж������Ƿ�ռ��
				if (board[x - 1][y - 1] == ' ')
				{
					board[x - 1][y - 1] = '#';
					break;
				}
				else
				{
					printf("���걻ռ�ã������䣡\a\n");
				}
			}
			else
			{
				printf("����Ƿ������������룡\a\n");
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
				return 0;//����û��
		}
	}
	return 1;//��������
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
	//�ж���
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

	//�ж���
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

	//�ж����ϵ�����б��
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

	//�ж����ϵ�����б��
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

	//�ж�ƽ��
	 int ret = IsFull(board, row, col);
	 if (ret)
	 {
		 return 'Q';
	 }	 
	 return 'C';
}