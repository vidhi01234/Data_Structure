#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data;
	struct stack *next;
} sl;

sl * insert(sl*);
sl * deletion(sl*);
void display(sl*);
sl * new_before_first(sl*);
sl * new_after_last(sl*);
sl * new_before_last(sl*);

int main()
{
	int ch;
	sl *top=NULL;
	do
	{
		printf("\n1.Insert\n2.Deletion\n3.display\n4.before_first\n5.After_last\n6.before_last");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			top=insert(top);
			break;
		case 2:
			top= deletion(top);
			break;
		case 3:
			display(top);
			break;
		case 4:
			top=new_before_first(top);
			break;
		case 5:
			top=new_after_last(top);
			break;
		case 6:
			top=new_before_last(top);
			break;
		}
	} while(ch<7);
	return 0;
}

sl * insert(sl *tp)
{
	int d;
	sl *p=NULL;
	p=(sl*) malloc (sizeof(sl));
	if(p!=NULL)
	{
		printf("Enter value:");
		scanf("%d",&d);
		p->data=d;
		p->next=tp;
		tp=p;
	}
	else
	{
		printf("Memory not allocated");
	}
	return tp;
}

sl * deletion(sl *tp)
{
	sl *p=NULL;
	if(tp==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		p=tp;
		printf("\n%d ",tp->data);
		tp=tp->next;
		free(p);
	}
	return tp;
}

void display(sl *tp)
{
	if(tp==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(tp!=NULL)
		{
			printf("%d ",tp->data);
			tp=tp->next;
		}
	}
}

sl * new_before_first(sl*tp)
{
	int x;
	sl *p=NULL;
	p=(sl*) malloc (sizeof(sl));
	if(p!=NULL)
	{
		printf("Enter value");
		scanf("%d",&x);
		p->data=x;
		p->next=tp->next;
		tp->next=p;
		return tp;
	}
}

sl* new_after_last(sl*tp)
{
	int x;
	sl *p=NULL,*l=NULL;
	l=tp;
	p=(sl*) malloc (sizeof(sl));
	printf("Enter value");
	scanf("%d",&x);
	p->data=x;
	while(l->next!=NULL)
	{
		l=l->next;
	}
	l->next=p;
	p->next=NULL;
	return tp;
}

sl* new_before_last(sl *tp)
{
	int x;
	sl *p=NULL, *l=NULL;
	l=tp;
	p=(sl*) malloc (sizeof(sl));
	if(p!=NULL)
	{
		printf("Enter value");
		scanf("%d",&x);
		p->data=x;
		while(l->next->next!=NULL)
			l=l->next;
		p->next=l->next;
		l->next=p;
	}
	return tp;
}
