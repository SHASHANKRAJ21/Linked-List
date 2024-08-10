#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(){
        this->next=NULL;
    }
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
int getlength(node *head){
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void printll(node *head){
    node *temp=head;
    int len=0;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        int a=len++;
        temp=temp->next;
    }
    cout<<endl;
}
void insert_new_node_at_first(node* &head,node* &tail,int data){
    if(head==NULL){
        node*newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node*newnode=new node(data);
        newnode->next=head;
        head=newnode;
        }
}
void insert_at_tail(node* &head,node*  &tail,int data){
    if(head==NULL){
        node*newnode=new node(data);
        head=newnode;
    }
    else{
        node *newnode=new node(data);
        tail->next=newnode;
        tail=newnode;
    }
}
void insert_at_position(node* &head,node* &tail,int data,int position){
    int length=getlength(head);
    if(position<=1){
        insert_new_node_at_first(head,tail,data);
    }
    else if(position>length){
        insert_at_tail(head,tail,data);
    }
    else{
        node *newnode=new node(data);
        node*prev=head;
        // node*curr=head;
        while((position-1)!=1){
            prev=prev->next;
            // curr=curr->next;
            position--;
        }
        newnode->next=prev->next;
        prev->next=newnode;

    }
}

int main(){
    node*first=new node(10);
    node*second=new node(20);
    node*third=new node(30);
    node*fourth=new node(40);
    node*fifth=new node(50);
    node*sixth=new node(60);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
    node*head=first;
    node*tail=sixth;
    cout<<"printing the entire linked list"<<endl;
    printll(head);
   // cout<<"printing the length of the linked list"<<endl;
    //int len=length(head);
    //cout<<len;
    // insert_new_node_at_first(head,tail,100);
    // printll(head);
    // insert_at_tail(head,tail,400);
    // printll(head);
    insert_at_position(head,tail,200,6);
    printll(head);

}