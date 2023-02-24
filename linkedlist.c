
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_linkedlist(struct node *start);
void display_linkedlist(struct node *start);
void count_linkedlist(struct node *start);
void search_node(struct node *start,int data);
struct node *add_at_beg(struct node *start,int data);
struct node *add_at_end(struct node *start,int data);
struct node *add_at_pos(struct node *start,int pos,int data);
struct node *add_before(struct node *start,int data,int item);
struct node *add_after(struct node *start,int data,int item);
struct node *del_at_beg(struct node *start);
struct node *del_at_end(struct node *start);
struct node *del_at_pos(struct node *start,int pos);

int main()
{
	int pos,data,item;
	int choice;
	struct node *start = NULL;
	while(1)
	{
		printf("1	:Enter 1 to create the linked list \n");
		printf("2 	:Enter 2 to display the linked list \n");
		printf("3	:Enter 3 to count nodes of linked list \n");
		printf("4	:Enter 4 to add node at beginning of the list \n");
		printf("5	:Enter 5 to add node at end of the list \n");
		printf("6	:Enter 6 to add node at particular position \n");
		printf("7	:Enter 7 to add node before the paticular node \n");
		printf("8	:Enter 8 to add node after the particular node \n");
		printf("9	:Enter 9 to delete node at the beginning \n");
		printf("10	:Enter 10 to delete node at the end \n");
		printf("11	:Enter 11 to delete node at particular postion \n");
		printf("12	:Enter 12 to search node in linked list \n");
		printf("13	:Enter 13 to quit from the program \n");
		printf("Enter your choice \n");
		scanf("%d",&choice);



		switch(choice)
		{
		 	case 1:
				start=create_linkedlist(start);
				break;
			case 2:
				display_linkedlist(start);
				break;
			case 3:
				count_linkedlist(start);
				break;
			case 4:
				printf("Enter the data to add at beginning \n");
				scanf("%d",&data);
				start = add_at_beg(start,data);
				break;
			case 5:
				printf("Enter the data to add at end \n");
				scanf("%d",&data);
				start = add_at_end(start,data);
				break;
			case 6:
				printf("Enter the data,pos to insert at pos \n");
				scanf("%d%d",&data,&pos);
				start = add_at_pos(start,data,pos);
				break;
			case 7:
				printf("Enter the data and item to add before \n");
				scanf("%d%d",&data,&item);
				start = add_before(start,data,item);
				break;
			case 8:
				printf("Enter the data and item to add after\n");
				scanf("%d%d",&data,&item);
				start = add_after(start,data,item);
				break;
			case 9:
				start = del_at_beg(start);
				break;
			case 10:
				start = del_at_end(start);
				break;
			case 11:
				printf("Enter the position to delete the node \n");
				scanf("%d",&pos);
				start = del_at_pos(start,pos);
				break;
			case 12:
				printf("Enter the data to be searched \n");
				scanf("%d",&data);
				search_node(start,data);
				break;
			case 13:
				exit(1);
			default:
				printf("Wrong choice \n");
		}
	}
}
void display_linkedlist(struct node *start)
{
	struct node *temp =start;
	while(temp->link != NULL)
	{
		printf("%d\t",temp->info);
		temp = temp->link;
	}
	printf("\n");
}
void count_linkedlist(struct node *start)
{
	struct node *temp = start;
	int count=0;
	while(temp->link != NULL)
	{
		temp=temp->link;
		count++;
	}
	printf("Nodes in the list are %d \n",count);
	printf("\n");
}
struct node *add_at_beg(struct node *start,int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info= data;
	temp->link = start;
	start = temp;
	return start;
}
struct node *add_at_end(struct node *start,int data)
{
	struct node *temp,*p;
	temp = (struct node *)malloc(sizeof(struct node));
	p = start;
	while(p->link != NULL)
	{
		p = p->link;
	}
	p->link = temp;
	temp->info = data;
	temp->link = NULL;
	return start;
}
struct node *add_at_pos(struct node *start,int pos,int data)
{
	struct node *temp,*p;
	p =start;
	for(int i = 0;p->link != NULL ;i++)
	{
		p = p->link;
		if( i == (pos-1))
		{
			temp->link = p->link;
			temp->info = data;
			p->link = temp;
		}
	}
	return start;
}
struct node *add_before(struct node *start,int data,int item)
{
	struct node *temp,*p;
	if( start === NULL)
	{
		printf("List is Empty \n");
		return start;
	}
	if ( start->info == item)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->link = start;
		temp->info = data;
		start = temp;
		return start;
	}
	p=start;
	while ( p->link != NULL)
	{
		if(p->link->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->link = p->link;
			temp->info = data;
			p->link = temp;
			return start;
		}
		p=p->link;
	}

	printf("%d is not present in the list \n",item);
	return start;
}
struct node *add_after(struct node *start,int data,int item)
{
	struct node *temp,*p;
	if(start == NULL)
	{
		printf("List is Empty \n");
		return start;
	}
	if(start->info == item)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		start->link = temp;
		temp->info=data;
		temp->link = NULL;
		return start;
	}
	p=start;
	while(p->link != NULL)
	{
		if(p->info == item)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->link = p->link;
			p->link = temp;
			temp->info = data;
			return start;
		}
		p = p->link;
	}
	printf("%d is not in the list\n",item);
	return start;
}
struct node *create_linkedlist(struct node *start)
{
	struct node *start = NULL;
	int node_num,data;
	printf("Enter Number of Nodes \n");
	scanf("%d",&node_num);
	printf("Enter the starting node data \n");
	scanf("%d",&data);
	add_at_beg(start,data);
	for(int i=2;i<=node_num;i++)
	{
		printf("enter %d node info\n",i);
		scanf("%d",data);
		add_at_end(start,data);
	}
	return start;
}
struct node *del_at_beg(struct node *start)
{
	struct node *temp = start;
	start = temp->link;
	free(temp);
	return start;
}
struct node *del_at_end(struct node *start)
{
	struct node *temp,*p
	p=start;
	while (p->link != NULL)
	{
		p = p->link;
	}
	temp = start;
	while(temp->link != p)
	{
		temp = temp->link;
	}
	temp->link = NULL;
	free(p);
	return start;
}
struct node *del_at_pos(struct node *start,int pos)
{
	struct node *temp,*p;
	temp = start;
	for(int i = 0; temp->link != NULL;i++)
	{
		if(i == (pos-1))
		{
			p = temp;
		}
		temp=temp->link;
		p->link = temp;
		free(temp);
	}
	return start;
}
struct node *search_node(struct node *start,int data)
{
	struct node *temp=start;
	int pos=1;
	while(temp->link != NULL)
	{
		if(temp->info == data)
		{
			printf("%d is found at %d node \n",data,pos);
			return start;
		}
		temp = temp->link;
		pos++;
	}
	printf("%d is not present in the list \n",data);
	return start;
}


			
			



	







		





