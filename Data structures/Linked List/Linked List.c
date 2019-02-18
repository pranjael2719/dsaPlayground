#include <stdio.h>
#include <stdlib.h>
struct node {	
	int data;
	struct node *link;
};
struct node *head=NULL;
void insert(int d)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=d;
	temp->link=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		struct node *p;
		p=head;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int length()
{
	struct node *p;
	int count=0;
	p=head;
	while(p!=NULL)
	{
		p=p->link;
		count++;
	}
	return count;
}
void delete()
{
	struct node *p, *temp;
	int count=0,i=1;
	if(head==NULL)
	printf("List is Empty");
	else
	{
		count=length();
		p=head;
		if(count==1)
		{
			temp=head;
			head=NULL;
			free(temp);
		}
		else
		{
			while(i<count-1)
			{
				p=p->link;
				i++;
			}
			temp=p->link;
			p->link=NULL;
			free(temp);	
		}
	}
}
void update(int x,int d)
{
	struct node *p;
	if (x>length())
	printf("Location Given is not Valid\n");
	else
	{
		int i=0;
		struct node *p;
		p=head;
		while(i<x-1)
		{
			p=p->link;
			i++;
		}
		p->data=d;
	}
}
void display()
{
	struct node *p;
	if(head==NULL)
	printf("List is Empty.\n");
	else
	{
		p=head;
		while(p!=NULL)
		{
			printf("%d\n",p->data);
			p=p->link;
		}
	}
}
int main()
{
	int c=1;
	int i,a,x;
	while(c==1)
	{
		printf("MENU\n1 for insert\n2 for delete\n3 for update\n4 for display\n5 for exit\nEnter your input ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: 
			printf("Enter the element to be inserted: ");
			scanf("%d",&a);
			insert(a);
			break;
			case 2: delete();
			break;
			case 3: printf("Enter the position to be updated: ");
			scanf("%d",&x);
			printf("Enter the value to be updated: ");
			scanf("%d",&a);
			update(x,a);
			break;
			case 4: display();
			break;
			case 5: exit(0);
			default: printf("Wrong Input");
		}
		printf("Do you want to continue?(0/1) ");
		scanf("%d",&c);
	}
}
