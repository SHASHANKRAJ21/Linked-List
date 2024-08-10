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
int length(node *head){
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
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
    cout<<"printing the entire linked list"<<endl;
    printll(head);
    cout<<"printing the length of the linked list"<<endl;
    int len=length(head);
    cout<<len;

}