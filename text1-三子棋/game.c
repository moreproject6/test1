#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//��ʼ����Ϊ�ո� 
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1.��ӡһ�е����� 
			printf(" %c ", board[i][j]);
			if (j< col-1 ) 
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ��� 
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col -1 )
					printf("|");
			}
			printf("\n");
		}

	}
}
//�����
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺>");
		scanf("%d%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//x��1-3��y��1-3
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����걻ռ�ã�����������\n");
		}
		else
			printf("����Ƿ�������������\n");
	}
}
//������ 
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж������Ƿ�����
//����1��ʾ��������
//����0��ʾ����û��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(board[i][j]==' ')
			return 0;//û��
		}
	}
	return 1;//����
}

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�жϺ����� 
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//�ж�������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//�����Խ���
	if (board[1][1] == board[0][0] && board[2][2] == board[0][0] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[2][0] == board[0][0] && board[0][2] != ' ')
		return board[0][0];
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return'C';
}
