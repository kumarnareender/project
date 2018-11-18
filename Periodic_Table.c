#include<stdio.h>
#include<string.h>
#include<conio.h>

char Main_Menu()
{
	system("COLOR 06");
	char menu;
	
	printf("\n\nN-Search By Name\n");
	printf("S-Search By Symbol\n");
	printf("A--Search By Atomic Number\n");
	printf("Q-Quit\n");
	
	menu=getche();
	return menu;
}

char Sub_Menu()
{
	char menu;
	
	printf("\n\n\n\t\t\tB-Back\t\t\t\t\t");
	printf("M-Main Menu\n\n\n\n");
	menu=getch();
	
	system("CLS");
	return menu;
}

void Background()
{
	printf("\n\n\t\t\t\tModern Period Table");
	printf("\n\n\t\t---------------------------------------------------\n\n\n\n\n\n\n");
}

char Upper_Case(char menu)
{
	if(menu<=122 && menu>=97)
	{
		menu=menu-32;
	}
	return menu;
}

void Element_Name(char name[20])
{
	int i,line=0,number;
	char search[20],symbol[5],menu;
	float weight;
	FILE *EN,*AN,*AW,*S;
	
	EN=fopen("Element Name.txt","r+");
	AW=fopen("Atomic Weigth.txt","r+");
	AN=fopen("Atomic Number.txt","r+");
	S=fopen("Symbol.txt","r+");
	
	while(strcmp(name,search) != 0)
	{
		fscanf(EN," %[^\n]s",search);
		line++;
		if(feof(EN))
		{
			printf("No Iformation Available\n");
			line=0;
			{
			menu=Sub_Menu();
			if(menu=='B')
				printf("Enter Element Name\n");
				scanf(" %[^\n]s",name);
				Element_Name(name);
			}
			break;
		}
	}
	if(line != 0)
	{
		system("cls");
		Background();
		printf("Name\t\t%s\n",name);
		for(i=0;i<line;i++)
		{
			fscanf(S," %s",symbol);
			fscanf(AN,"%d",&number);
			fscanf(AW,"%f",&weight);
		}
		printf("Symbol\t\t%s\n",symbol);
		printf("Atomic Number\t%d\n",number);
		printf("Atomic Weigth\t%.3f\n",weight);
		menu=Sub_Menu();
		if(menu=='B')
		{
			printf("Enter Element Name\n");
			scanf(" %[^\n]s",name);
			Element_Name(name);
			system("CLS");
		}
	}
}
void Element_Symbol(char symbol[5])
{
	int i,line=0,number;
	char search[20],name[20];
	float weight;
	
	FILE *EN,*AN,*AW,*S;
	
	EN=fopen("Element Name.txt","r+");
	AW=fopen("Atomic Weigth.txt","r+");
	AN=fopen("Atomic Number.txt","r+");
	S=fopen("Symbol.txt","r+");
	
	while(strcmp(symbol,search) != 0)
	{
		fscanf(S," %[^\n]s",search);
		line++;
		if(feof(S))
		{
			printf("No Iformation Available\n");
			line=0;
			break;
		}
	}
	
	if(line != 0)
	{
		system("cls");
		Background();
		for(i=0;i<line;i++)
		{
			fscanf(EN," %s",name);
			fscanf(AN,"%d",&number);
			fscanf(AW,"%f",&weight);
		}
		printf("Name\t\t%s\n",name);
		printf("Symbol\t\t%s\n",symbol);
		printf("Atomic Number\t%d\n",number);
		printf("Atomic Weigth\t%.3f\n",weight);
		getch();
		system("CLS");
	}
}
void Element_Number(int number)
{
	int i;
	char name[20],symbol[5];
	float weight;
	FILE *EN,*AN,*AW,*S;
	EN=fopen("Element Name.txt","r+");
	AW=fopen("Atomic Weigth.txt","r+");
	AN=fopen("Atomic Number.txt","r+");
	S=fopen("Symbol.txt","r+");
	if(number<=118)
	{
		system("cls");
		Background();
		for(i=0;i<number;i++)
		{
			fscanf(EN," %s",name);
			fscanf(S," %s",symbol);
			fscanf(AW,"%f",&weight);
		}
		printf("Name\t\t%s\n",name);
		printf("Symbol\t\t%s\n",symbol);
		printf("Atomic Number\t%d\n",number);
		printf("Atomic Weigth\t%.3f\n",weight);
		getch();
		system("CLS");
	}
}
int main()
{
	
	system("COLOR F0");
	int number;
	char menu,name[20],symbol[5];
	Background();
	while(menu != 'Q')
	{
		menu=Main_Menu();
		menu=Upper_Case(menu);
		system("CLS");
		if(menu=='N')
		{
			Background();
			printf("Enter Element Name\n");
			scanf(" %[^\n]s",name);
			name[0]=Upper_Case(name[0]);
			Element_Name(name);
		}
		if(menu=='S')
		{
			Background();
			printf("Enter Element Symbol\n");
			scanf(" %s",symbol);
			symbol[0]=Upper_Case(symbol[0]);
			Element_Symbol(symbol);
		}
		if(menu=='A')
		{
			Background();
			printf("Enter Element Number\n");
			scanf("%d",&number);
			Element_Number(number);
		}
	}
}
