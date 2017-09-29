/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Yousif Dafalla
 *
 * Created on September 28, 2017, 5:07 PM
 */
/* This is a list generic class it can be used for different types*/

#ifndef LIST_H
#define LIST_H
typedef float itemType;
struct NodeType;
class List
{
public:
    List();
    void Insert(itemType);
    bool IsEmpty() const;
    bool HasNext() const;
    void ResetList();
    itemType GetNextItem();
    void Delete();
    void printItems() const;
    
private:
    NodeType * head;
    NodeType * current;
    NodeType * tail;
    int length;
};


#endif /* LIST_H */

