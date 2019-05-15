#include<stdio.h>
int binary_search(int n)
{
	int low = 2, high = 19;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (fibArray[mid] == n)
			return mid;
		else if (fibArray[mid] > n)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int checkFibSeries(int **gameBoard, int rows, int cols, int sr, int sc, int er, int ec)
{
	int check1 = gameBoard[sr][sc];
	int check2 = gameBoard[er][ec];
	if (check1 == check2 && check1==1)
		return 1;
	int g, s;
	if (check1 > check2)
	{
		g = check1;
		s = check2;
	}
	else
	{
		g = check2;
		s = check1;
	}
	int pos=binary_search(s);
	if (fibArray[pos + 1] == g)
		return 1;
	return 0;
	
}
int isPossibleUp(int **gameBoard, int rows, int cols,int sr, int sc, int er, int ec,int *pos)
{
	int i;
	for (i = sr - 1; i >= er; i--)
	{
		*pos = i;
		if (gameBoard[i][sc])
			return checkFibSeries(gameBoard, rows, cols, sr, sc, i, ec);
	}
	return 0;
}
int isPossibleRight(int **gameBoard, int rows, int cols, int sr, int sc, int er, int ec, int *pos)
{
	int j;
	for (j = sc+1; j < ec; j++)
	{
		pos[0] = j;
		if (gameBoard[sr][j] )
			return checkFibSeries(gameBoard, rows, cols, sr, sc, er, j);
	}
	return 0;
	
}
int isPossibleDown(int **gameBoard, int rows, int cols, int sr, int sc, int er, int ec, int *pos)
{
	int i;
	for (i = sr + 1; i < er; i++)
	{
		*pos = i;
		if (gameBoard[i][sc])
			return checkFibSeries(gameBoard, rows, cols, sr, sc, i, ec);
	}
	return 0;
}
int isPossibleLeft(int **gameBoard, int rows, int cols, int sr, int sc, int er, int ec, int *pos)
{
	int  j;
	for (j = sc - 1; j >= ec; j--)
	{
		pos[0] = j;
		if (gameBoard[sr][j])
			return checkFibSeries(gameBoard, rows, cols, sr, sc, er, j);
	}
	return 0;

}
char enterMove()
{
	char n;
	printf("enter your Move:\nW->Up\nA->Left\nS->Down\nD->Right\n");
	scanf("\n%c",&n);
	return n;
}
void moveUp(int **gameBoard, int rows, int cols, char move)
{
	int i, j, k, pos = 0;
	for (j = 0; j < cols; j++)
	{
		for (i = rows-1; i >= 1; i--)
		{
			pos = -1;
			if (gameBoard[i][j] && isPossibleUp(gameBoard, rows, cols, i, j, 0, j, &pos))
			{
				gameBoard[pos][j] += gameBoard[i][j];
				pos++;
				gameBoard[i][j] = 0;
				for (k = i + 1; k < rows; k++)
				{
					gameBoard[pos++][j] = gameBoard[k][j];
					gameBoard[k][j] = 0;
				}
				int count_zeroes = 0, n1 = 0, n2 = 0, n3 = 0;
				for (k = 0; k < rows; k++)
				{
					if (!gameBoard[k][j])
						count_zeroes++;
					else
					{
						if (!n1)
							n1 = gameBoard[k][j];
						else if (!n2)
							n2 = gameBoard[k][j];
						else if (!n3)
							n3 = gameBoard[k][j];
						gameBoard[k][j] = 0;
					}

				}
				if (rows == 4)
				{
					if (count_zeroes == 1)
					{
						gameBoard[2][j] = n3;
						gameBoard[1][j] = n2;
						gameBoard[0][j] = n1;
					}
					else if (count_zeroes == 2)
					{
						gameBoard[1][j] = n2;
						gameBoard[0][j] = n1;
					}
					else if (count_zeroes == 3)
					{
						gameBoard[0][j] = n1;
					}
				}
				else
				{
					if (count_zeroes == 1)
						gameBoard[0][j] = n1;
				}
			
				break;
			}
			else if (gameBoard[i][j] && pos != i)
			{
				if (gameBoard[pos][j])
					pos += 1;
				if (pos != i)
				{
					for (k = i; k < rows; k++)
					{
						gameBoard[pos++][j] = gameBoard[k][j];
						gameBoard[k][j] = 0;
					}
				}
			}

		}
	}
}
void moveLeft(int **gameBoard, int rows, int cols, char move)
{
	int i, j, pos, k;
	for (i = 0; i < rows; i++)
	{
		for (j = cols - 1; j >= 1; j--)
		{
			pos = -1;
			if (gameBoard[i][j] && isPossibleLeft(gameBoard, rows, cols, i, j, i, 0, &pos))
			{
				gameBoard[i][pos] += gameBoard[i][j];
				gameBoard[i][j] = 0;
				pos += 1;
				for (k = j + 1; k < cols; k++)
				{
					gameBoard[i][pos++] = gameBoard[i][k];
					gameBoard[i][k] = 0;
				}
				int count_zeroes = 0, n1 = 0, n2 = 0, n3 = 0;
				for (k = 0; k < cols; k++)
				{
					if (!gameBoard[i][k])
						count_zeroes++;
					else
					{
						if (!n1)
							n1 = gameBoard[i][k];
						else if (!n2)
							n2 = gameBoard[i][k];
						else if (!n3)
							n3 = gameBoard[i][k];
						gameBoard[i][k] = 0;
					}

				}
				if (cols == 4)
				{
					if (count_zeroes == 1)
					{
						gameBoard[i][2] = n3;
						gameBoard[i][1] = n2;
						gameBoard[i][0] = n1;
					}
					else if (count_zeroes == 2)
					{
						gameBoard[i][1] = n2;
						gameBoard[i][0] = n1;
					}
					else if (count_zeroes == 3)
					{
						gameBoard[i][0] = n1;
					}
				}
				else
				{
					if (count_zeroes)
						gameBoard[i][0] = n1;
				}
				break;
			}
			else if (gameBoard[i][j] && pos!=j)
			{
				if (gameBoard[i][pos])
					pos += 1;
				if (pos != j)
				{
					for (k = j; k < cols; k++)
					{
						gameBoard[i][pos++] = gameBoard[i][k];
						gameBoard[i][k] = 0;
					}
				}
			}
		}
	}

}
void moveRight(int **gameBoard, int rows, int cols, char move)
{
	int i, j, pos,k;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols-1; j++)
		{
			pos = -1;
			if (gameBoard[i][j] && isPossibleRight(gameBoard, rows, cols, i, j, i, cols, &pos))
			{
				int main_pos;
				gameBoard[i][pos] += gameBoard[i][j];
				gameBoard[i][j] = 0;
				main_pos = pos;
				pos -= 1;
				for (k = j-1; k >= 0; k--)
				{
					gameBoard[i][pos--] = gameBoard[i][k];
					gameBoard[i][k] = 0;
				}
				int count_zeroes = 0,n1=0,n2=0,n3=0;
				for (k = 0; k < cols; k++)
				{
					if (!gameBoard[i][k])
						count_zeroes++;
					else
					{
						if (!n1)
							n1 = gameBoard[i][k];
						else if (!n2)
							n2 = gameBoard[i][k];
						else if (!n3)
							n3 = gameBoard[i][k];
						gameBoard[i][k] = 0;
					}

				}
				if (cols == 4)
				{
					if (count_zeroes == 1)
					{
						gameBoard[i][3] = n3;
						gameBoard[i][2] = n2;
						gameBoard[i][1] = n1;
					}
					else if (count_zeroes == 2)
					{
						gameBoard[i][cols - 1] = n2;
						gameBoard[i][cols - 2] = n1;
					}
					else if (count_zeroes == 3)
					{
						gameBoard[i][cols - 1] = n1;
					}
				}
				else
				{
					if (count_zeroes == 1)
					{
						gameBoard[i][1] = n1;
					}
				}
				break;
			}
			else if (gameBoard[i][j] && pos!=j)
			{
				if (gameBoard[i][pos])
					pos -= 1;
				if (pos != j)
				{
					for (k = j; k >= 0; k--)
					{
						gameBoard[i][pos--] = gameBoard[i][k];
						gameBoard[i][k] = 0;
					}
				}
			}
		}
	}
}
void moveDown(int **gameBoard, int rows, int cols, char move)
{
	int i, j, k, pos = 0;
	for (j = 0; j < cols; j++)
	{
		for (i = 0; i < rows - 1; i++)
		{
			pos = -1;
			if (gameBoard[i][j] && isPossibleDown(gameBoard, rows, cols, i, j, rows, j, &pos))
			{
				gameBoard[pos][j] += gameBoard[i][j];
				pos--;
				gameBoard[i][j] = 0;
				for (k = i - 1; k >= 0; k--)
				{
					gameBoard[pos--][j] = gameBoard[k][j];
					gameBoard[k][j] = 0;
				}
				int count_zeroes = 0, n1 = 0, n2 = 0, n3 = 0;
				for (k = 0; k < rows; k++)
				{
					if (!gameBoard[k][j])
						count_zeroes++;
					else
					{
						if (!n1)
							n1 = gameBoard[k][j];
						else if (!n2)
							n2 = gameBoard[k][j];
						else if (!n3)
							n3 = gameBoard[k][j];
						gameBoard[k][j] = 0;
					}

				}
				if (rows == 4)
				{
					if (count_zeroes == 1)
					{
						gameBoard[3][j] = n3;
						gameBoard[2][j] = n2;
						gameBoard[1][j] = n1;
					}
					else if (count_zeroes == 2)
					{
						gameBoard[rows - 1][j] = n2;
						gameBoard[rows - 2][j] = n1;
					}
					else if (count_zeroes == 3)
					{
						gameBoard[rows - 1][j] = n1;
					}
				}
				else
				{
					if (count_zeroes == 1)
						gameBoard[1][j] = n1;
				}
				break;
			}
			else if (gameBoard[i][j] && pos != i)
			{
				if (gameBoard[pos][j])
					pos -= 1;
				if (pos != i)
				{
					for (k = i; k >= 0; k--)
					{
						gameBoard[pos--][j] = gameBoard[k][j];
						gameBoard[k][j] = 0;
					}
				}
			}

		}
	}
}
void evaluateMove(int **gameBoard,int rows,int cols,char move)
{
	if (move == 'W' || move == 'w')
		moveUp(gameBoard, rows, cols, move);
	else if (move == 'A' || move == 'a')
		moveLeft(gameBoard, rows, cols, move);
	else if (move == 'S' || move == 's')
		moveDown(gameBoard, rows, cols, move);
	else
		moveRight(gameBoard, rows, cols, move);
}