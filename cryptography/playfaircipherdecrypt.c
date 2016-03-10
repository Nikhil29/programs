#include<stdio.h>
#include<malloc.h>

int generatematrix(char matrix[5][5],char str[])
{
	int i,check[26],counter=0;
	for(i=0;i<26;i++)
	{
		check[i]=0;
	}
	for(i=0;str[i]!='\0';i++)
	{
		if(check[str[i]-97]==1)
		{
			continue;
		}
		else
		{
			check[str[i]-97]=1;
			matrix[counter/5][counter%5]=str[i];
			counter++;
			if(check[8]==1||check[9]==1)
			{
				check[8]=1;
				check[9]=1;
			}
		}
	}
	check[9]=1;
	for(i=0;i<26;i++)
	{
		if(check[i]==0)
		{
			check[i]=1;
			matrix[counter/5][counter%5]=i+97;
			counter++;
		}
	}
	return 0;
}

struct pair
{
	int row,col;
};

struct pair* search(char c,char matrix[5][5])
{
	int i,j;
	struct pair *x=malloc(sizeof(struct pair));
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(c==matrix[i][j]||(c=='i'&&matrix[i][j]=='j')||(c=='j'&&matrix[i][j]=='i'))
			{
				x->row=i;
				x->col=j;
				break;
			}
		}
	}
	return x;
}

int main()
{
	char str[100],matrix[5][5],a1,a2,end;
	int i,j;
	struct pair *coor1,*coor2;

	// file containing the gtext to be encrypted
	FILE *input=fopen("playfaircipheroutput","r");
	FILE *output=fopen("playfaircipherinput","w");
	
	// input string as key for decryption
	printf("Enter the key for decryption in lowercase characters: ");
	scanf("%s",str);

	generatematrix(matrix,str);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",matrix[i][j]);
		}
		printf("\n");
	}

	while(1)
	{
		a1=' ';
		while(a1==' ')
		{
			end=fscanf(input,"%c",&a1);
			if(end==-1)
				break;
		}
		if(end==-1)
			break;
		a2=' ';

		while(a2==' ')
		{
			end=fscanf(input,"%c",&a2);
			if(end==-1)
			{
				a2='x';
			}
		}
		if(a1==a2)
			a2='x';

		coor1=search(a1,matrix);
		coor2=search(a2,matrix);

		if(coor1->row==coor2->row)
		{
			printf("%c%c -> %c%c\n",matrix[coor1->row][coor1->col],matrix[coor2->row][coor2->col],matrix[coor1->row][(coor1->col-1+5)%5],matrix[coor1->row][(coor2->col-1+5)%5] );
			fprintf(output,"%c%c",matrix[coor1->row][(coor1->col-1+5)%5],matrix[coor1->row][(coor2->col-1+5)%5]);
		}
		else if(coor1->col==coor2->col)
		{
			printf("%c%c -> %c%c\n",matrix[coor1->row][coor1->col],matrix[coor2->row][coor2->col],matrix[(coor1->row-1+5)%5][coor1->col],matrix[(coor2->row-1+5)%5][coor1->col] );
			fprintf(output,"%c%c",matrix[(coor1->row-1+5)%5][coor1->col],matrix[(coor2->row-1+5)%5][coor1->col]);
		}
		else
		{
			printf("%c%c -> %c%c\n",matrix[coor1->row][coor1->col],matrix[coor2->row][coor2->col],matrix[coor1->row][coor2->col],matrix[coor2->row][coor1->col] );
			fprintf(output,"%c%c",matrix[coor1->row][coor2->col],matrix[coor2->row][coor1->col]);
		}
	}
	return 0;
}
