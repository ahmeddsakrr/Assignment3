//
// Created by ahmed on 28-Jul-22.
//
#include "List.h"
#include <bits/stdc++.h>
using namespace std;

List::List(int maxSize) : mySize(0),myCapacity(maxSize) {
    myArray=new ElementType [maxSize];
}

List::~List() {
    delete [] myArray;
}

bool List::empty() const {
    return !mySize;
}

void List::insert(ElementType item, int pos) {
    if (mySize==myCapacity){
        cout<<"Error - No space for inserting - List is Full";
    }else{
        if (pos<0||pos>mySize){
            cout<<"Error - Invalid insertion position";
            return ;
        }
        for (int i = mySize; i>pos ; --i) {
            myArray[i]=myArray[i-1];
        }
        myArray[pos]=item;
        mySize++;
    }
}

void List::erase(int pos) {
    if(empty()){
        cout<<"Error - List is Empty";
        return;
    }
    if(pos<0 || pos>=mySize){
        cout<<"Error in Erasing - Invalid Position\n";
        return ;
    }
    if (!List::empty()){
        for (int i = pos; i <mySize-1 ; ++i) {
            myArray[i]=myArray[i+1];
        }
        mySize--;
    }
}

void List::display(std::ostream &out) const {
    for (int i = 0; i < mySize; ++i) {
        out<<myArray[i]<<" ";
    }
    out<<"\n";
}

List::List(const List &origList):mySize(origList.mySize),myCapacity(origList.myCapacity) {
    myArray=new ElementType [myCapacity];
    if(myArray){
        for (int i = 0; i < mySize; ++i) {
            myArray[i]=origList.myArray[i];
        }
    }else{
        cerr<<"Error in allocating memory";
        return ;
    }
}

const List &List::operator=(const List &rightHandSide) {
    assert(this!=&rightHandSide);
    this->~List();
    myArray=new ElementType [rightHandSide.myCapacity];
    if(myArray){
        for (int i = 0; i < mySize; ++i) {
            myArray[i]=rightHandSide.myArray[i];
        }
    }else{
        cerr<<"Error in allocating memory";
        exit(1);
    }
    return *this;
}

ostream & operator<< (ostream & out, const List & aList){
    aList.display(out);
    return out;
}

int List::get(int index) {
    return myArray[index];
}

void List::push_back(ElementType elementType) {
    this->insert(elementType,mySize);
}