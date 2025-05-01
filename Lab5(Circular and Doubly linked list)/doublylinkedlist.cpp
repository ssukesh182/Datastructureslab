#include<iostream>

using namespace std;

class List{

    private:
    struct Node{
        struct Node *prev;
        int data;
        struct Node *next;
    }*head;

    struct Node *tail=NULL;

    public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void insertBegin(int);
    void insertEnd(int);
    void insertPos(int,int);
    int count();
    void deleteBegin();
    void deleteEnd();
    void deletePos(int);
    void search(int);
    void display();
};

int List::count()
{

    if(head==NULL || tail==NULL)
    {
        return 0;
    }
    struct Node *ptr=head;
    int cnt=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        cnt++;
    }
    return cnt;
}
void List::insertBegin(int data)
{
    if(head==NULL)
    {
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;

    }
}
void List::insertEnd(int data)
{
    if(head==NULL)
    {
        insertBegin(data);
    }
    else{

        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        newnode->next=NULL;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }

}
void List::insertPos(int data ,int pos)
{
    struct Node *ptr=head;
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;

    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    struct Node *q=ptr->next;
    newnode->prev=ptr;
    newnode->next=q;
    ptr->next=newnode;
}

void List::deleteBegin()
{
    if(head==NULL)
    {
        cout<<"List is Empty:\n";
        return ;

    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else{
        struct Node *p=head;
        cout<<head->data<<endl;
        head=p->next;
        head->prev=NULL;
        free(p);
        p=NULL;
         
    }
}

void List::deleteEnd()
{
    if(head == NULL || tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    else if(head == tail)  // Only one element in the list
    {
        free(tail);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct Node *p = tail;
        tail = p->prev;
        tail->next = NULL;  // Disconnect the old tail from the list
        free(p);
        p = NULL;
    }
}


void List::deletePos(int pos)
{

    if(head==NULL || tail==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else if(pos<0 || pos> count() )
    {
        cout<<"Invalid Position"<<endl;
    }
    else{
        struct Node *ptr=head;
   

         while(pos!=1)
         {
           ptr=ptr->next;
           pos--;
         }
         struct Node *q=ptr->next->next;
         struct Node *p=ptr->next;
         ptr->next=q;
         q->prev=ptr;
         free(p);
         p=NULL;   
    }
}

void List::search(int data)
{
    struct Node *ptr=head;
    int flag=0;
    while(ptr!=NULL)
    {
        if(ptr->data==data)
        {
            cout<<"Element is Found"<<endl;
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==0)
    {
        cout<<"Element is not Found"<<endl;
    }
}
int main()
{
    List l1;
    while(1)
    {
        cout<<"1.Insertion at Beginning:\n";
        cout<<"2.Insertion at End\n";
        cout<<"3.Insertion at a Position"<<endl;
        cout<<"4.Deletion at Begin"<<endl;
        cout<<"5.Deletion at End"<<endl;
        cout<<"6.Deletion at a position"<<endl;
        cout<<"7.Search"<<endl;
        cout<<"8.Display"<<endl;
        cout<<"9.Exit"<<endl;
        int choice,data,pos;
        cout<<"Enter a Choice :"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
             cout<<"Enter data to enter:"<<endl;
             cin>>data; 
             l1.insertBegin(data);
             break;
        case 2:
             cout<<"Enter data to enter:"<<endl;
             cin>>data; 
             l1.insertEnd(data);
             break;
        case 3:
             cout<<"Enter data to enter:"<<endl;
             cin>>data; 
             cout<<"Enter correct position to insert:"<<endl;
             cin>>pos;
             l1.insertPos(data,pos);
             break;
        case 4:
             l1.deleteBegin();
             break;
        case 5:
             l1.deleteEnd();
             break;
        case 6:
            cout<<"Enter correct position to delete:"<<endl;
            cin>>pos;
            l1.deletePos(pos);
            break;
        case 7:
             cout<<"Enter the data to check:"<<endl;
             cin>>data;
             l1.search(data);
             break;
        case 8:
            l1.display();
            break;
        case 9:
             cout<<"Thank You"<<endl;
             exit(1);
        }
    }
}

void List::display()
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}
