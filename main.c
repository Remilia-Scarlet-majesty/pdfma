#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"add.c"
#include"DeleteTag.c"
#include"del.c"
#include"sort.c"
#include"def.h"
#include"AddTag.c"
#include"printbook.c"
#include"show.c"
#include"star.c"
#include"unstar.c"
#include"udffind.c"
#include"status.c"
#include"changecat.c"
int main()
{
	int n;
	char c='y';
	while(c=='y'){
	printf("1-���һ�������Ϣ");
	printf("          ");
	printf("2-���ݱ�ǩ����\n");
	printf("3-ɾ��һ�����й���Ϣ"); 
	printf("        ");
	printf("4-ɾ��һ�����ĳ��ǩ\n");
	printf("5-Ϊĳ������ӱ�ǩ");
	printf("          ");
	printf("6-��ӡ��Ϣ\n");
	printf("7-����Ǻ�          "); 
	printf("        ");
	printf("8-������\n");
	printf("9-�鿴����鼮");
	printf("              ");
	printf("10-��ʾ״̬\n");
	printf("11-ģ����������");
	printf("             ");
	printf("12-�����Ķ�״̬\n");
	printf("13-�����鼮����������");
	printf("     ");
	printf("14-�����鼮�������\n");
	printf("0-exit\n");
	printf("please input the number.\n");
	scanf("%d",&n);
	if(n>=0&&n<=14)
	{
		switch(n){
			case 1:addbook();break;
			case 2:sort1();break;
			case 3:delbook();break;
			case 4:deltag();break;
			case 5:addtag();break;
			case 6:printbook();break;
			case 7:star();break;
			case 8:unstar();break;
			case 9:show();break;
			case 10:status();break;
			case 11:udffind();break;
			case 12://����zmr 
			case 13:sort2();break;
			case 14:changecat();break;
			case 0:return 0;
		}
	}
	printf("If you want to continue,press y.else  ��㰴\n");
	c=getch();
	putchar(c);
	putchar('\n');
}
}

