#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

int main()
{
    node *head = new node();
    head->data = 12;
    head->next = NULL;

    node *current = new node();
    current->data = 10; 
    head->next = NULL;

    head->next = current;  

    current = new node();
    current->data = 90;
    head->next = NULL;

    head->next->next = current;  

    cout<< head->data << " " << head->next <<  " " << endl;
    cout<< current->data << " " << head->next <<  " " << endl;
    cout<< current->data << " " << head->next->next <<  " " << endl;
}