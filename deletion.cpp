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
int getlength(node *head){
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void deleting(node* &head,node* &tail,int position ){

    int length=getlength(head);
    if(head==NULL){
        cout<<"that the list is empty can't delete element";
    }
    if(head==tail){
        node*temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    if(position==1){
        node*temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else if(position==length){
        node*prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
        prev->next=NULL;
        delete tail;
        tail=prev;

    }
    else{
        node*prev=NULL;
        node*curr=head;
        while(position!=NULL){
            prev=curr;
            curr=curr->next;
            position--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr; 

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
    // printll(head);
    // cout<<"printing the length of the linked list"<<endl;
    // int len=length(head);
    // cout<<len;
    deleting(head,tail,6);
    printll(head);

}