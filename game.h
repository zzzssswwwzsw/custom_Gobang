#pragma once

//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//符号的定义
//棋盘行数
#define ROW 3
//棋盘列数
#define COL 3
//赢棋个数
#define CHESS_NUM 3


//函数的声明

//设置界面
int setting(int input_setting, int* model);
//游戏主体
void game();
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家1下棋
void Player1Move(char board[ROW][COL], int row, int col);

//玩家2下棋
void Player2Move(char board[ROW][COL], int row, int col, int model);

//判断棋盘是否满了
//满了返回值为1
//不满返回值为0
int IsFull(char board[ROW][COL], int row, int col);

//判断是否有输赢
//1. 玩家1赢 - *
//2. 玩家2赢 - #
//3. 平局 - Q
//4. 游戏继续 - C
char IsWin(char board[ROW][COL], int row, int col, int Count_Player1, int Count_Player2);

//求得row和col的最大值
int MAX(int row, int col);