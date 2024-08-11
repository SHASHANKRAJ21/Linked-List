#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node()
    {
        this->prev = NULL;
        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int getlength(node *head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertatfirst(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        node *newnode = new node(data);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insertatend(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        node *newnode = new node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insertatposition(node *&head, node *&tail, int data,int position){
    node* prev=NULL;
    node *curr=head;
    node *temp=head;
    while(position!=1){
        position--;
        prev=curr;
        curr=curr->next;
    }
    node *newnode=new node(data);
    prev->next=newnode;
    newnode->prev=prev;
    newnode->next=curr;
    curr->prev=newnode;
}
void deleting(node *&head, node *&tail, int data){
    if(head==NULL){
        cout<<"sorry our array is empty we cant delet any item";
    }
    

}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertatfirst(head, tail, 10);
    insertatfirst(head, tail, 20);
    insertatfirst(head, tail, 30);
    insertatfirst(head, tail, 40);
    insertatfirst(head, tail, 50);
    print(head);
    cout<<endl; 
    insertatend(head, tail, 100);
    print(head);
    cout<<endl;
    insertatposition(head,tail,1000,3);
    print(head);
    return 0;
}