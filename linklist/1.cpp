#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

int main()
{
    node* n1 = new node();
    n1->data = 50;
    n1->next = NULL;

    node* n2 = new node();
    n2->data = 80;
    n2->next = NULL;

    n1->next = n2;

    node* n3 = new node();
    n3->data = 50;
    n3->next = NULL;

    n2->next = n3;

    cout<<  n1->data << " " << n1->next  << " " << endl;
    cout<<  n2->data << " " << n2->next  << " " << endl;
    cout<<  n3->data << " " << n3->next  << " " << endl;
}   