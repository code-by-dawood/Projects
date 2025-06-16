#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class sll{
    private:
    Node* head;
    
    public:
    
    sll()
    {
        head=NULL;
    }
    void insert(int element)
    {
        Node* node=new Node(element);
        node->next=head;
        head=node;
    }
    
    void disp()
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        
        cout<<"nullptr";
    }
};
int main()
{
    sll ob;
    int size,i=0;
    cout<<"Enter capacity:";cin>>size;
    int arr[size];
    
    
    cout<<"Enter elements\n";
    while(i<size)
    {
        scanf("%d",&arr[i]);
        ob.insert(arr[i]);
        i++;
    }
    
    ob.disp();
    return 0;
}