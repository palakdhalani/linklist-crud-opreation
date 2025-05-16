#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};



int main()
{
    node *ptr = NULL;
    node*head = new node(10);
    ptr=head;

    node*current = new node(20);
    head->next = current;

    current = new node(30);
    head->next->next = current;

    current = new node(40);
    head->next->next->next = current;
    

    while (ptr != NULL)
    {
        cout<< ptr->data<< " - " << ptr->next << endl;
        ptr = ptr-> next;
    }
}