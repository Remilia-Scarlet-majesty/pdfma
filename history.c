#include<stdio.h>
#include"cal.c"
#include<stdlib.h>
struct work{
	char n[100];
	char t[100];
	int p1;
	int p2;
	int delta;
};
void history(){
	int d,i;
	FILE*fp;
	if ((fp=fopen("calm.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	fclose(fp);
	struct work *tem;
	tem=malloc(d*sizeof(struct work));
	if((fp=fopen("time.csv","r"))==NULL)
   {
   	printf("cannot open\n");
   }
   char c;
   for(i=0;i<d;i++)
		{
			while((c=fgetc(fp))!='\n')
			{
				putchar(c);
			}
   			fscanf(fp,"%s",tem[i].n);
   			fseek(fp,1L,SEEK_CUR);
   			fscanf(fp,"%d",&tem[i].p1);
   			fseek(fp,7L,SEEK_CUR);
   			fscanf(fp,"%d",&tem[i].p2);
   			fseek(fp,6L,SEEK_CUR);
   			fscanf(fp,"%d",&tem[i].delta);
   			printf("%s\n",tem[i].t);
   			printf("%s %dpages->%dpages,%dmore.\n",tem[i].n,tem[i].p1,tem[i].p2,tem[i].delta);
		}
		
	fclose(fp);
}
