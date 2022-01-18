#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
void create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first=new Node();
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
		t=new Node();
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
		
	}
}
void create2(int A[],int n)
{
	int i;
	struct Node *t,*last;
	second=new Node();
	second->data=A[0];
	second->next=NULL;
	last=second;
	for(i=1;i<n;i++)
	 {
	 t=new Node();
	 t->data=A[i];
	 t->next=NULL;
	 last->next=t;
	 last=t;
	 }
}
void display(struct Node *p)
{
	
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
		
	}
}
int count(struct Node *p)
{
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
		
	}
	return l;
	
}
void insert(struct Node *p,int index,int x)
{
	struct Node *t;
	int i;
	if(index < 0 || index > count(p))
 		return;
	t=new Node();
	t->data=x;
	if(index==0)
	{
		t->next=first;
		first=t;
	}
	else{
		for(i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}
int delet(struct Node *p,int index)
{
	struct Node *q=NULL;
	int x=-1,i;
	if(index < 0 || index > count(p))
		return 0;
	if(index==0)
	{
		q=first;
		x=first->data;
		first=first->next;
		delete(q);
		return x;
	}
	else{
		for(i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		delete(p);
		return x;
	}
	
}
int issorted(struct Node *p)
{
	int x=-65536;
	while(p)
	{
		if(p->data <x)
			return 0 ;
		x=p->data;
		p=p->next;
	}
	return 1;
}
void Merge(struct Node *p,struct Node *q)
{
 struct Node *last;
 if(p->data < q->data)
 {
 third=last=p;
 p=p->next;
 third->next=NULL;
 }
 else
 {
 third=last=q;
 q=q->next;
 third->next=NULL;
 }
 while(p && q)
 {
 if(p->data < q->data)
 {
 last->next=p;
 last=p;
 p=p->next;
 last->next=NULL;
 
 }
 else
 {
 last->next=q;
 last=q;
 q=q->next;
 last->next=NULL;
 
 }
 }
 if(p)last->next=p;
 if(q)last->next=q;
 
}
void reverse(struct Node *p)
{
	struct Node *q=NULL,*r=NULL;
	while(p!=NULL)
	{
	r=q;
	 q=p;
	 p=p->next;
	 q->next=r;	
	}
	first=q;
	
}
void duplicate(struct Node *p)
{
	struct Node *q=p->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
			
		}
		else
		{
			p->next=q->next;
			delete q;
			q=p->next;
		}
	}
}
int main()
{
	 int A[]={10,20,30,40,50};
	 int B[]={15,18,25,25,55};
 create(A,5);
 create2(B,5);
 insert(first,3,5);
 insert(first,4,6);
 delet(first,3);
 Merge(first,second);
 reverse(first);
 duplicate(second);
 display(second);
 cout<<issorted(first);
}
