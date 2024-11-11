#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	//ѡ��ʼ���˳���Ϸ
	int input_menu = 0;
	//ѡ������
	int input_setting = 0;
	//ѡ��ģʽֵ
	// 1Ϊ����
	// 2Ϊ˫��
	int model = 1;
	//�����2һ�����������
	srand((unsigned int)time(NULL));
	do
	{
		printf("*************************************\n");
		printf("*��ǰ��Ϸģʽ��%d��ģʽ***************\n", model);
		printf("*************************************\n");
		printf("***********   %d������Ϸ  ************\n", CHESS_NUM);
		printf("***********   1. play     ***********\n");
		printf("***********   0. exit     ***********\n");
		printf("***********   2. setting  ***********\n");
		printf("*************************************\n");
		printf("*************************************\n");
		printf("��ѡ��");
		scanf("%d", &input_menu);
		switch (input_menu)
		{
		case 2:
			setting(input_setting, &model);
			break;
		case 1:
			printf("%d������Ϸ��ʼ\n", CHESS_NUM);
			game(model);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\a\n");
			break;
		}
	} while (input_menu);
}

int setting(int input_setting, int* model)
{
	while (1)
	{
		printf("**************************************\n");
		printf("*********** ��ѡ���ս���� ***********\n");
		printf("*********** 1. ��ս�˻�    ***********\n");
		printf("*********** 2. ˫�˶�ս    ***********\n");
		printf("**************************************\n");
		printf("��ѡ��");
		scanf("%d", &input_setting);
		switch (input_setting)
		{
		case 1:
			*model = 1;
			return 0;
			break;
		case 2:
			*model = 2;
			return 0;
			break;
		default:
			printf("������������䣡\a\n");
			break;
		}
	}
}

void game(int model)
{
	//��ά���飬�洢����
	char board[ROW][COL];

	//��ʼ������ - ��ʼ���ո�
	InitBoard(board, ROW, COL);

	//��ӡ���� -�����Ǵ�ӡ���������
	DisplayBoard(board, ROW, COL);

	//������Ϸ״̬
	char ret = 0;
	int Count_Player1 = 0;
	int Count_Player2 = 0;


	while (1)
	{
		//���1����
		Player1Move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL, Count_Player1, Count_Player2);
		//�������ֵ��ΪC����˵����Ϸ����
		if (ret != 'C')
			break;
		
		//���2����
		Player2Move(board, ROW, COL, model);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL, Count_Player1, Count_Player2);
		//�������ֵ��ΪC����˵����Ϸ����
		if (ret != 'C')
			break;
		
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬���ʤ����\n");
	}
	else if (ret == '#')
	{
		printf("�ˣ�\n");
	}
	else
	{
		printf("�ⶼ��ƽ�֣�����\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{	
	menu();
	return 0;
}