
#include<conio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "fileHandler.h"
int fibArray[20];
#include "gameBoard.h"
#include "gameMove.h"
int main()
{
	struct player *p1=create_player();
	createFibArray();
	int n=playGame();
	int rows, cols,winning_number;
	if (n == 1)
	{
		rows = 2, cols = 2;
		winning_number = 7;
	}
	else
	{
		rows = 4, cols = 4;
		winning_number = 2048;
	}
	int x,max;
	int **gameBoard = createBoard(rows,cols);
	do
	{
		showPlayer(p1);
		showBoard(gameBoard,rows,cols);
		char move=enterMove();
		updateMoveCount(p1);
		evaluateMove(gameBoard,rows,cols,move);
		x=place_tile(gameBoard, rows, cols);
		max = get_max_number(gameBoard, rows, cols);
		system("cls");
	//	showBoard(gameBoard, rows, cols);
		//break;
	} while (max< winning_number && x);
	system("cls");
	if (max >= winning_number){
		printf("%s have won in %d number of moves.\n", p1->name, p1->number_of_moves);
		handleFile(p1,rows);
	}
	else
		printf("%s have lost in %d number of moves.\n", p1->name, p1->number_of_moves);
	_getch();
}
