#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	//选择开始或退出游戏
	int input_menu = 0;
	//选择设置
	int input_setting = 0;
	//选择模式值
	// 1为单人
	// 2为双人
	int model = 1;
	//给玩家2一个坐标随机数
	srand((unsigned int)time(NULL));
	do
	{
		printf("*************************************\n");
		printf("*当前游戏模式：%d人模式***************\n", model);
		printf("*************************************\n");
		printf("***********   %d子棋游戏  ************\n", CHESS_NUM);
		printf("***********   1. play     ***********\n");
		printf("***********   0. exit     ***********\n");
		printf("***********   2. setting  ***********\n");
		printf("*************************************\n");
		printf("*************************************\n");
		printf("请选择：");
		scanf("%d", &input_menu);
		switch (input_menu)
		{
		case 2:
			setting(input_setting, &model);
			break;
		case 1:
			printf("%d子棋游戏开始\n", CHESS_NUM);
			game(model);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\a\n");
			break;
		}
	} while (input_menu);
}

int setting(int input_setting, int* model)
{
	while (1)
	{
		printf("**************************************\n");
		printf("*********** 请选择对战人数 ***********\n");
		printf("*********** 1. 对战人机    ***********\n");
		printf("*********** 2. 双人对战    ***********\n");
		printf("**************************************\n");
		printf("请选择：");
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
			printf("输入错误，请重输！\a\n");
			break;
		}
	}
}

void game(int model)
{
	//二维数组，存储数据
	char board[ROW][COL];

	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);

	//打印棋盘 -本质是打印数组的内容
	DisplayBoard(board, ROW, COL);

	//接收游戏状态
	char ret = 0;
	int Count_Player1 = 0;
	int Count_Player2 = 0;


	while (1)
	{
		//玩家1下棋
		Player1Move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL, Count_Player1, Count_Player2);
		//如果返回值不为C，则说明游戏结束
		if (ret != 'C')
			break;
		
		//玩家2下棋
		Player2Move(board, ROW, COL, model);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL, Count_Player1, Count_Player2);
		//如果返回值不为C，则说明游戏结束
		if (ret != 'C')
			break;
		
	}
	if (ret == '*')
	{
		printf("恭喜你，获得胜利！\n");
	}
	else if (ret == '#')
	{
		printf("菜！\n");
	}
	else
	{
		printf("这都能平局？？？\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{	
	menu();
	return 0;
}