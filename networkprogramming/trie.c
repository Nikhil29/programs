#include<stdio.h>
#include<stdlib.h>
struct node
{
	int counter;
	struct node *new[26];
};
struct node *createnode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->counter=0;
	int i;
	for(i=0;i<26;i++)
		temp->new[i]=NULL;
}
void insert(char *a,struct node *temp)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		int c=a[i]-'a';
		if(temp->new[c]==NULL)
		{
			temp->new[c]=createnode();
			temp=temp->new[c];
		}
		else
			temp=temp->new[c];

	}
	temp->counter++;
}
int check(struct node *temp,char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		int c=a[i]-'a';
		if(temp->new[c]!=NULL)
		{
	//		temp->new[a[i]-'a']=createnode();
			temp=temp->new[c];
		}
		else
			return 0;
	}
	return temp->counter;
}
int main()
{
	//char *a[5][10];
	//printf("Enter any word");
	int i;
	struct node *start=createnode();

	/*for(i=0;i<5;i++)
	{
		scanf("%s",a[i]);
		insert(a[i],start);	
	}*/
	
	insert("hello",start);
	insert("hello",start);
	insert("hello",start);
	int no=check(start,"hello");
	printf("%d",no);
	return 0;
}