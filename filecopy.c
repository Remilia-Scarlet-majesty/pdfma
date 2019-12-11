#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
void  udfcopy()
{	DIR *dp;
	struct dirent *entry;
	int i=0,num,d;
	char fname[50][25];
	char path1[50],path2[50];
	char cmd[130]="copy ";
	char tem[25];
	printf("Please input the path of the file you want to copy\n");
	scanf("%s",path1);
	if((dp=opendir(path1))==NULL)
	printf("Wrong input.\n");
	else
	{	printf("File List:\n");
		while((entry=readdir(dp))!=NULL&&i<49)
		{	strcpy(tem,entry->d_name);
			if(strcmp(entry->d_name,"..")!=0&&strcmp(entry->d_name,".")!=0)
			{
			printf("%dth:%s\n",i+1,entry->d_name);
			strcpy(fname[i],entry->d_name);
			i++;
			}
		}
		closedir(dp);
	}
	printf("How many file do you want to copy?Input the num.\n");
	scanf("%d",&num);
	int *no;
	no=malloc(num*sizeof(int));
	printf("Please input the NO. of ordering file.\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&no[i]);
		no[i]--;
	}
	printf("Please input the target path.\n");
	scanf("%s",path2);
	for(i=0;i<num;i++)
	{	
		strcat(cmd,path1);
		strcat(cmd,"\\");
		strcat(cmd,fname[no[i]]);
		strcat(cmd," ");
		strcat(cmd,path2);
		system(cmd);
		strcpy(cmd,"copy ");
	}
	free(no); 
}
