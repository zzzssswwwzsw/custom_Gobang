#pragma once

//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���ŵĶ���
//��������
#define ROW 3
//��������
#define COL 3
//Ӯ�����
#define CHESS_NUM 3


//����������

//���ý���
int setting(int input_setting, int* model);
//��Ϸ����
void game();
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);

//���1����
void Player1Move(char board[ROW][COL], int row, int col);

//���2����
void Player2Move(char board[ROW][COL], int row, int col, int model);

//�ж������Ƿ�����
//���˷���ֵΪ1
//��������ֵΪ0
int IsFull(char board[ROW][COL], int row, int col);

//�ж��Ƿ�����Ӯ
//1. ���1Ӯ - *
//2. ���2Ӯ - #
//3. ƽ�� - Q
//4. ��Ϸ���� - C
char IsWin(char board[ROW][COL], int row, int col, int Count_Player1, int Count_Player2);

//���row��col�����ֵ
int MAX(int row, int col);