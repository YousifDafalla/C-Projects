/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<cstddef>
#include<iostream>
using namespace std;
#include "List.h"
typedef NodeType* NodePtr;
struct NodeType
{
    itemType component;
    NodePtr link;
};

List::List()
{
    head=NULL;
    current=NULL;
    tail=NULL;
    length=0;
}

void List::Insert(itemType item)
{
    NodePtr newNode=new NodeType;
    newNode->link=NULL;
    newNode->component=item;
    if(length==0)
    {
        head=newNode;
        tail=newNode;
        current=newNode; 
    }
    else
    {
        tail->link=newNode;
        tail=newNode;
    }
    length++;
}

bool List::IsEmpty() const
{
    return (length==0);
}

bool List::HasNext() const
{
    return (current!=NULL);
}

void List::ResetList()
{
    current=head;
}

itemType List::GetNextItem()
{
    itemType item;
    item=current->component;
    current=current->link;
    return item;
}

void List::Delete()
{
    itemType item;
    cout<<"Enter the number you want to delete: ";
    cin>>item;
    NodePtr currentPtr=head;
    NodePtr previous=NULL;
    if(length==0)
        cout<<"Empty list\n";
    else
    {
        while(currentPtr!=NULL && currentPtr->component!=item)
        {
            previous=currentPtr;
            currentPtr=currentPtr->link;
        }
        if(currentPtr!=NULL)
        {
            //Item is found
            if(current==head)
                head=current->link;
            else
                previous->link=current->link;
            
            if(current==tail)
                tail=previous;
            
            //delete currentPtr;
            length--;
            
        }
        else
            cout<<"Item not found try again!\n";
        
    }
}

void List::printItems() const
{
    int i=1;
    NodePtr pNav=head;
    while(pNav!=NULL)
    {
        cout<<"Item "<<i<<": "<<pNav->component<<endl;
        i++;
        pNav=pNav->link;
    }
}