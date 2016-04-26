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
				printf("                         * ��ӭʹ�ó��ݹ�ѧԺУ԰����ϵͳ*                          \n");
				printf("��������������������������������������������������������������������������������\n");
				printf("��                ������Ϣ��ѯ�������������������밴 1 ��                     �� \n");
				printf("��                �������·����ѯ���������������밴 2 ��                     ��\n");
				printf("��                �����������·����ѯ�����������밴 3 ��                     ��\n");
				printf("��                �˳�ϵͳ�����������������������밴 4 ��                     ��\n");
				printf("��������������������������������������������������������������������������������\n");
				printf("ѧУ�����б�:\n");
				printf("0:����     ");
				printf("1:һʳ��   ");
				printf("2:��ʳ��   ");
				printf("3:ͼ���   ");
				printf("4:����\n");
				printf("5:���¥   ");
				printf("6:������   ");
				printf("7:Ժʿ���� ");
				printf("8:Ժʿ¥   ");
				printf("9:��ʳ��\n");
				printf("��ѡ�����:");
				scanf("\n%d",&k);
				switch(k)
				{
				case 1:
					printf("���뾰����Ϣ��ѯ��\n������������������������������������loading������������������������������������\n");
					introduce();
					break;
				case 2:
					printf("�������·����ѯ��\n����������������������������������loading��������������������������������������\n");
					shortestdistance();
					break;
				case 3:
					printf("���뾰�������·����ѯ��\n������������������������������������loading������������������������������������\n");
                    int start,finish;
	                cin >> start;
	                cin >> finish; 
	                Print(start, finish);
					break;
				case 4:
					exit(0);
				default:
					printf("������Ϣ����\n������1��2��3��4.\n");
					break;
				}
			}
}

void introduce()
{
	int a;
	printf("�����ѯ�ĸ��������ϸ��Ϣ?\n�����뾰����:");
	scanf("%d",&a);
	getchar();
	printf("\n");
	switch(a)
	{
	case 0:
		printf("0:ѧУ����\n\n ѧУ�����ţ����������ĵط�����Ȼ��̫С��\n\n");
		break;
	case 1: 
		printf("1:һʳ��\n\n ѧ����Ҫ���ò͵ص㣬��ɫ���߹�����ζ���ء�\n\n");
		break;
	case 2:
		printf("2:��ʳ��\n\n ��¥���ἰ��ʦ��Ҫ�ò͵ص㡣\n\n");
		break;
	case 3:
		printf("3:ͼ���\nѧ����֪��ϰ�ĵط���֪ʶ�ĺ��� ��\n\n");
		break;
	case 4:
		printf("4:����\n\n ѧУ���ţ���ΰ���ɡ�\n\n");
		break;
	case 5:
		printf("5:���¥\n\n ѧ��ʵ�����ġ�\n\n");
		break;
	case 6:
		printf("6:������\n\n ѧ����������ġ�\n\n");
		break;
	case 7:
		printf("7:Ժʿ����\n\n ����Ժ�������㣬��ʷ�ƾá�\n\n");
		break; 
	case 8:
		printf("8:Ժʿ¥\n\n ѧ����Ҫ�Ͽεص㣬ֻ�������о�߯С�˵㡣\n\n\n");
		break;
	case 9:
		printf("9:��ʳ�� \n\n λ���е�ƫԶ��\n\n");
		break;
	default:
		printf("�������������������0��9�����ֱ�ţ�\n\n"); 
		break; 
	}
}
int shortestdistance()
{
	int i,j;
	printf("\n������Ҫ��ѯ����������ı��:\n");
	scanf("%d%d",&i,&j);
	if(i>n||i<0||j>n||j<0)
	{
		printf("�������������\n\n");
		printf(" ������Ҫ��ѯ����������ı��:\n");
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
	printf("��Ҫ��ѯ������������·����:\n\n");
	if(shortest[i][j]!=INT_MAX)
	{
		if(i<j)
		{
			printf("%d",a);
			while(path[i][j]!=0)
			{
				printf("��%d",path[i][j]);
				if(i<j)
					j=path[i][j];
				else
					i=path[j][i];
			}
			printf("��%d",b);
			printf("\n\n");
			printf("(%d��%d)��̾�����:%d��\n\n",a,b,shortest[a][b]); 
		}
		else
		{
			printf("%d",a);
			while(path[i][j]!=0)
			{
				printf("��%d",path[i][j]);
				if(i<j)
					j=path[i][j];
				else
					i=path[j][i];
			}
			printf("��%d",b);
			printf("\n\n");
			printf("(%d��%d)��̾�����:%5d��\n\n",a,b,shortest[a][b]);
		}
	}
	else
		printf("������󣡲����ڴ�·��\n\n");
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
