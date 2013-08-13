#include "highscore.h"


void highscore(int newScore)
{
	/*
	int lenS = strlen(newScore);
	newScore[lenS] = '\n';
	newScore[lenS+1] = 0;	//dangerous
	*/
	FILE *fp = fopen("data/highscore.dat", "r");
	char name[10][100] = {};
	int score[10] = {};
	char newName[100] = {};
	int i;
	
	for (i=0; i<10; i++)
	{
		fgets(name[i], 100, fp);
		//fgets(score[cnt++], 100, fp);
		fscanf(fp, "%d\n", &score[i]);
	}
	//printf("newScore: %s\n", newScore);
	//printf("cnt: %d\n", cnt);
	
	/*
	if ()
	{
		while (strcmp(newScore, score[--cnt])==1 && cnt>=0)
			;
		printf("new high score, please input your name\n");
		scanf("%s", newName);
		newName[strlen(newName)] = '\n';
		for (i=8; i>cnt; i--)
		{
			strcpy(name[i+1], name[i]);
			strcpy(score[i+1], score[i]);
		}
		strcpy(name[cnt+1],newName);
		strcpy(score[cnt+1],newScore);
	}
	*/
	int ret = 0;
	
	while (i>0 && newScore>score[--i])
	{
		score[i+1] = score[i];
		strcpy(name[i+1], name[i]);
		ret = 1;
	}
	if (1 == ret)
	{
		printf("new high score, please input your name\n");
		//fgets(newName, 100, stdout);
		scanf("%s", newName);
		int len = strlen(newName);
		newName[len] = '\n';
		newName[len+1] = 0;
		if (i != 0)
		{
			strcpy(name[i+1], newName);
			score[i+1] = newScore;
		}
		else
		{
			strcpy(name[0], newName);
			score[0] = newScore;
		}
	}
	
	
	
	printf("%s","\033[1H\033[2J");
	printf("high score table\n");
	for (i=0; i<10; i++)
	{
		printf("%d.%s %d\n", i+1, name[i], score[i]);
	}
	fclose(fp);
	fp = NULL;
	fp = fopen("data/highscore.dat", "w");
	for (i=0; i<10; i++)
	{
		fputs(name[i], fp);
		fprintf(fp, "%d\n", score[i]);
	}
	fclose(fp);
}
