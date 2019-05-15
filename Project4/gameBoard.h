#include<stdio.h>
#include<stdlib.h>
void createFibArray()
{
	fibArray[0] = 0,fibArray[1]=1;
	int i = 2;
	while (i<20)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
		i++;
	}
	//for (i = 1; i < 20; i++)
		//printf("%d\n", fibArray[i]);
}
int get_max_number(int **gameboard,int rows,int cols)
{
	int max = 0;
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (gameboard[i][j]>max)
				max = gameboard[i][j];
		}
	}
	return max;
}
int place_tile(int **board,int rows,int cols)
{
	int pos[16];
	int npos = 0;
	int i, j, p;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (board[j][i] == 0) pos[npos++] = j * cols + i;
		}
	}

	if (npos == 0) return 0;  

	p = pos[rand() % npos];
	j = p / cols;
	i = p % rows;

	board[j][i] = 1;
	return 1;
}
int playGame()
{
	int n;
	printf("select your option:\n1.2*2 Board\n2.4*4 Board\n");
	scanf("%d", &n);
	return n;
}
int** createBoard(int rows,int cols)
{
	int **array = (int **)malloc((rows + 1)*sizeof(int *));
	int i;
	for (i = 0; i <= rows; i++)
		array[i] = (int *)calloc((cols + 1),sizeof(int));
	i = rand() % rows;
	int j = rand() % cols;
	array[i][j] = 1;
	i = rand() % rows;
	j = rand() % cols;
	array[i][j] = 1;
	return array;
}
void showBoard(int ** gameBoard,int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%d ", gameBoard[i][j]);
		printf("\n");
	}
}