#include<iostream>
using namespace std;

class List{
	private:
	struct node{
		int data;
		struct node *next;
	}*tail;
	public:
	List()
	{
		tail=NULL;
	}
	void insertBegin(int);
	void insertEnd(int);
	void deleteBegin();
	void deleteEnd();
	void deletePos(int);
	void display();



};
void List::insertBegin(int data){
	if(tail==NULL)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=temp;
		tail=temp;
	}
	else{
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=data;
		newnode->next=tail->next;
		tail->next=newnode;
		
	}
}

void List::insertEnd(int data)
{
	if(tail==NULL)
	{
		insertBegin(data);
        return;    //to avoid duplication of first node in case of circular list.
	}
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	struct node *temp=tail->next;
	tail->next=newnode;
	newnode->next=temp;
	tail=newnode;
}
void List::deleteBegin()
{
	if(tail==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	struct node *p=tail->next;
	tail->next=p->next;
	free(p);
	p=NULL;
}
void List::deleteEnd()
{
	if(tail==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	struct node *p=tail->next;
	while(p->next!=tail)
	{
		p=p->next;
	}
	p->next=tail->next;
	free(tail);
	tail=p;
}
void List::deletePos(int pos)
{
	if(tail==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}else if(pos>count())
	{
		cout<<"Invalid position"<<endl;
	}
	else{
		struct node *p=tail->next;
		while(pos!=1)
		{
			p=p->next;
			pos--;
		
		}	
		struct node *q=p->next;
		p->next=q->next;
		free(q);
		q=NULL;

	}
}
void List::display()
{
	if(tail==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	struct node *p=tail->next;
	do{
		cout<<p->data<<"->";
		p=p->next;
	}while(p!=tail->next);
	cout<<tail->next->data<<endl;
}

int main()
{
	List l1;
	l1.insertEnd(1);
	l1.insertEnd(2);
	l1.insertEnd(3);
	l1.insertEnd(4);
	l1.deletePos();
	l1.display();
}