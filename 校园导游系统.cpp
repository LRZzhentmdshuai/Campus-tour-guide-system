#include <cstdio>
#include <process.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;


#define n 10
#define MAX 10000


char name[30];
char introduction[100];
int cost[n][n];
int shortest[n][n];
int path[n][n];
void introduce();                                    
int shortestdistance();
void Floyed();
void Display(int i,int j);
void Print(int start, int finish);			
void PrintPath(vector<int> path,  int currentPos,  int finish); 


int pos[10][10] = { {0,1,0,0,0,0,0,0,0,0}, //0          
					{1,0,1,1,0,0,0,1,0,0}, //1
					{0,1,0,1,0,0,0,0,0,0}, //2
					{0,1,1,0,0,1,0,0,0,0}, //3
					{0,0,0,0,0,1,0,0,0,1}, //4
					{0,0,0,1,1,0,1,0,0,0}, //5
					{0,0,0,0,0,1,0,1,1,0}, //6
					{0,1,0,0,0,0,1,0,1,0}, //7
					{0,0,0,0,0,0,1,1,0,1}, //8
					{0,0,0,0,1,0,0,0,1,0}}; //9


void main()
{
	int i,j;
	int k;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			cost[i][j]=MAX;
			cost[0][1]=cost[1][0]=50;
			cost[1][2]=cost[2][1]=50;
			cost[1][3]=cost[3][1]=70;
			cost[1][7]=cost[7][1]=150;
			cost[2][3]=cost[3][2]=40;
			cost[3][5]=cost[5][3]=100;
			cost[4][9]=cost[9][4]=800;
			cost[4][5]=cost[5][4]=300;
			cost[5][6]=cost[6][5]=100;
			cost[6][7]=cost[7][6]=30;
			cost[6][8]=cost[8][6]=40;
			cost[7][8]=cost[8][7]=50;
			cost[8][9]=cost[9][8]=200;
			cost[0][0]=cost[1][1]=cost[2][2]=cost[3][3]=cost[4][4]=0;
			cost[5][5]=cost[6][6]=cost[7][7]=cost[8][8]=cost[9][9]=0;
			while(1)
			{
				printf("                         * 欢迎使用常州工学院校园导游系统*                          \n");
				printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("┃                景点信息查询………………………请按 1 键                     ┃ \n");
				printf("┃                景点最短路径查询…………………请按 2 键                     ┃\n");
				printf("┃                两景点间所有路径查询……………请按 3 键                     ┃\n");
				printf("┃                退出系统……………………………请按 4 键                     ┃\n");
				printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				printf("学校景点列表:\n");
				printf("0:南门     ");
				printf("1:一食堂   ");
				printf("2:二食堂   ");
				printf("3:图书馆   ");
				printf("4:西门\n");
				printf("5:秋白楼   ");
				printf("6:体育馆   ");
				printf("7:院士语林 ");
				printf("8:院士楼   ");
				printf("9:三食堂\n");
				printf("请选择服务:");
				scanf("\n%d",&k);
				switch(k)
				{
				case 1:
					printf("进入景点信息查询中\n··················loading··················\n");
					introduce();
					break;
				case 2:
					printf("进入最短路径查询中\n·················loading···················\n");
					shortestdistance();
					break;
				case 3:
					printf("进入景点间所有路径查询中\n··················loading··················\n");
                    int start,finish;
	                cin >> start;
	                cin >> finish; 
	                Print(start, finish);
					break;
				case 4:
					exit(0);
				default:
					printf("输入信息错误！\n请输入1或2或3或4.\n");
					break;
				}
			}
}

void introduce()
{
	int a;
	printf("您想查询哪个景点的详细信息?\n请输入景点编号:");
	scanf("%d",&a);
	getchar();
	printf("\n");
	switch(a)
	{
	case 0:
		printf("0:学校大门\n\n 学校的南门，人流量最大的地方，显然门太小。\n\n");
		break;
	case 1: 
		printf("1:一食堂\n\n 学生主要的用餐地点，特色菜瓦罐汤风味独特。\n\n");
		break;
	case 2:
		printf("2:二食堂\n\n 二楼包厢及教师主要用餐地点。\n\n");
		break;
	case 3:
		printf("3:图书馆\n学生求知自习的地方，知识的海洋 。\n\n");
		break;
	case 4:
		printf("4:西门\n\n 学校正门，宏伟气派。\n\n");
		break;
	case 5:
		printf("5:秋白楼\n\n 学生实验中心。\n\n");
		break;
	case 6:
		printf("6:体育馆\n\n 学生体育活动中心。\n\n");
		break;
	case 7:
		printf("7:院士语林\n\n 常工院著名景点，历史悠久。\n\n");
		break; 
	case 8:
		printf("8:院士楼\n\n 学生主要上课地点，只有两栋感觉忒小了点。\n\n\n");
		break;
	case 9:
		printf("9:三食堂 \n\n 位置有点偏远。\n\n");
		break;
	default:
		printf("景点编号输入错误！请输入0到9的数字编号！\n\n"); 
		break; 
	}
}
int shortestdistance()
{
	int i,j;
	printf("\n请输入要查询的两个景点的编号:\n");
	scanf("%d%d",&i,&j);
	if(i>n||i<0||j>n||j<0)
	{
		printf("景点编号输入错误！\n\n");
		printf(" 请输入要查询的两个景点的编号:\n");
		scanf("%d%d",&i,&j);
	}
	else
	{
		Floyed();
		Display(i,j);
	}
	return 0;
}

void Floyed()
{
	int i,j,k;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			shortest[i][j]=cost[i][j];
			path[i][j]=0;
		}
		for(k=1;k<=n;k++)
			for(i=0;i<=n;i++)
				for(j=0;j<=n;j++)
					if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
					{
						shortest[i][j]=shortest[i][k]+shortest[k][j];
						path[i][j]=k;
						path[j][i]=k;
					}
}

void Display(int i,int j)
{
	int a,b;
	a=i;
	b=j;
	printf("您要查询的两景点间最短路径是:\n\n");
	if(shortest[i][j]!=INT_MAX)
	{
		if(i<j)
		{
			printf("%d",a);
			while(path[i][j]!=0)
			{
				printf("至%d",path[i][j]);
				if(i<j)
					j=path[i][j];
				else
					i=path[j][i];
			}
			printf("至%d",b);
			printf("\n\n");
			printf("(%d至%d)最短距离是:%d米\n\n",a,b,shortest[a][b]); 
		}
		else
		{
			printf("%d",a);
			while(path[i][j]!=0)
			{
				printf("至%d",path[i][j]);
				if(i<j)
					j=path[i][j];
				else
					i=path[j][i];
			}
			printf("至%d",b);
			printf("\n\n");
			printf("(%d至%d)最短距离是:%5d米\n\n",a,b,shortest[a][b]);
		}
	}
	else
		printf("输入错误！不存在此路！\n\n");
	printf("\n");
}

void Print(int start,int finish)
{
	if (start == finish)
	{
		cout << start << " " << start << endl;
	}
	else
	{
		vector<int> path;								
		path.push_back(start);	
		PrintPath(path, start, finish);
	}
}

void PrintPath(vector<int> path, int currentPos, int finish)
{
	bool exist = false;
	for (int i = 0; i < 10; i++)
	{
		exist = false;
		if (pos[currentPos][i] == 1)
		{
			for (vector<int>::iterator iter = path.begin();						
					!exist && iter != path.end(); iter++)
			{
				if (*iter == i)
					exist = true;
			}
			if (!exist)
			{
				if (i == finish)
				{
					for (vector<int>::iterator iter = path.begin();				
							iter != path.end(); iter++)
					{
						cout << *iter << " ";
					}
					cout << i << endl;
				}
				else
				{
					path.push_back(i);
					PrintPath(path, i, finish);										
					path.pop_back();
				}
			}
		} 
	} 
} 
