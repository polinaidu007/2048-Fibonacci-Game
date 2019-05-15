#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player
{
	char *name;
	int number_of_moves = 0;
};
struct player * create_player()
{
	struct player *p1=(struct player *)malloc(1 * sizeof(struct player));
	char *name=(char*)malloc(20*sizeof(char));
	printf("enter name:\n");
	scanf("%[^\n]", name);
	p1->name = name;
	p1->number_of_moves = 0;
	return p1;
}
void updateMoveCount(struct player *p1)
{
	p1->number_of_moves++;
}
void showPlayer(struct player *p1)
{
	printf("Player name: %s\n", p1->name);
	printf("Number of moves: %d\n", p1->number_of_moves);
}