/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yousif Dafalla
 *
 * Created on September 28, 2017, 5:06 PM
 */

#include <cstdlib>
#include<iostream>
#include "List.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    List myList;
    myList.Insert(55.5);
    myList.Insert(66.6);
    myList.Insert(77.9);
    myList.Insert(95.6);
    myList.Delete();
    myList.printItems();
    while(myList.HasNext())
    {
        cout<<"Item: "<<myList.GetNextItem()<<endl;
    }

    return 0;
}

