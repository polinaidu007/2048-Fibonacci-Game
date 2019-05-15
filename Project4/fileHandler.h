#include<stdio.h>
void handleFile(struct player *p1, int n)
{
	
	FILE *fp = fopen("leaderboard.txt", "w");
	fprintf(fp, "%-15s%-15d%d", p1->name,p1->number_of_moves);
	fclose(fp);
}