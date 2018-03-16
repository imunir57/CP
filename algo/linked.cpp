#include<bits/stdc++.h>

using namespace std;

struct node
{
    int a;
    node *p;
};
node *head=NULL,*last=NULL;

void ins(int data)
{
    node *temp=new(node);
    temp->a=data;
    temp->p=NULL;
    if(head==NULL)
        head=last=temp;
    else
        last->p=last=temp;

}
void print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->a<<endl;
        temp=temp->p;
    }

}
int srch(int data)
{
    node *tmp=head;
    while(tmp!=NULL)
    {
        if(data==tmp->a)    ///if sorted
            return 1;
        else if(data < tmp->a)
            return 0;
        else
            tmp=tmp->p;
    }
    return 0;
}

void del(int data)
{
    node *temp=head;
    node *prev=NULL;
    while(temp!=NULL)
    {
        if(temp->a==data)
        {
            if(prev==NULL)
                head=temp->p;
            else
                prev->p=temp->p;
            return;
        }
        prev=temp;
        temp=temp->p;
    }
}
int main()
{
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ins(a);
    }
    print();
    cin>>a;
    del(a);
    print();

}
