#include<stdio.h>
#include<process.h>
#include"cal.c"
#include<stdlib.h>
#include"def.h"
#include<time.h>
void adjustbook()
{
	FILE *fp;
	int i,j,d,p1,adb,npage;
	d=readnum();
	struct pdf *tem;
	tem=malloc(d*sizeof(struct pdf));
	if ((fp=fopen("info.csv","r"))==NULL)
		{
			printf("cannot open info.csv .\n");
			exit(0);
		}
			for(i=0;i<d;i++)
		{
			fscanf(fp,"%s ,%d,%d,%d,%d,%s",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].star,&tem[i].lin,tem[i].cat);
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
			for(j=0;j<tem[i].lin;j++)
				{
					//avoid to input the ","
					fscanf(fp,"%s",tem[i].line[j]);
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
				if(tem[i].lin!=0){
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
		}
	fclose(fp);
	printf("Book List:\n");
	for(i=0;i<d;i++)
	printf("%dth %s   Page:%d   Finish:%d   TagNumbers:%d\n",i+1,tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
	printf("Which book's information do you want to adjust?Input the num of book\n");
	scanf("%d",&adb);
	p1=tem[adb-1].read;
	printf("Please input the page now you have read\n");
	scanf("%d",&npage);
	tem[adb-1].read=npage;
	printf("Done.\n");
	printf("Now the new information is:\n");
	printf("%dth %s   Page:%d   Finish:%d   TagNumbers:%d\n",adb,tem[adb-1].name,tem[adb-1].pageall,tem[adb-1].read,tem[adb-1].lin);
	FILE*hp;
		if ((hp=fopen("temp.csv","w"))==NULL)
		{
			printf("cannot open new info file. Process failed.\n");
			exit(0);
		}
	for(i=0;i<d;i++)
	{	
		fprintf(hp,"%s ,%d,%d,%d,%d,%s ,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].star,tem[i].lin,tem[i].cat);
		for(j=0;j<tem[i].lin;j++)
		{
			fprintf(hp,"%s ,",tem[i].line[j]);
		}
		//adjust to the initial format//adjust to the initial format
	fprintf(hp,"\n");
	}
	fclose(hp);
	remove("info.csv");
	rename("temp.csv","info.csv");
	time_t rawtime;
   struct tm *info;
   char buffer[80];
   time( &rawtime );
   info=localtime( &rawtime );
   if((fp=fopen("time.csv","a+"))==NULL)
   {
   	printf("cannot open\n");
   }
   fprintf(fp,"%s",asctime(info));
   fprintf(fp,"%s %dpages->%dpages,%dmore.\n",tem[adb-1].name,p1,npage,npage-p1);
   fclose(fp);
   plus3();
}
