#include "IntList.h"
#include <iostream>

using namespace std;

/*Default Constructor*/
IntList::IntList(){
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

/*Destructor*/
IntList::~IntList(){

}

/*Inserts node to front of list*/
void IntList::push_front(int value){
    IntNode *temp = new IntNode(value);
    temp->next = dummyHead->next;
    temp->prev = dummyHead;
    dummyHead->next->prev = temp;
    dummyHead->next = temp;
}

/*Inserts node to end of list*/
void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    temp->next = dummyTail;
    temp->prev = dummyTail->prev;
    dummyTail->prev->next = temp;
    dummyTail->prev = temp;
}

/*Removes front node of list*/
void IntList::pop_front(){
    if(!empty()){
        IntNode *temp = dummyHead->next;
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
    }
}

/*Removes last node of list*/
void IntList::pop_back(){
    if(!empty()){
        IntNode *temp = dummyTail->prev;
        temp->prev->next = dummyTail;
        dummyTail->prev = temp->prev;
        delete temp;
    }
}

/*Returns true if list is empty*/
bool IntList::empty() const{
    return (dummyHead->next == dummyTail);
}

/*Prints the list in reverse order*/
void IntList::printReverse() const{
    IntNode *curr = dummyTail->prev;
    while(curr != dummyHead){
        if(curr->prev == dummyHead){
            cout << curr->data;
        } else {
            cout << curr->data << " ";
        }
        curr = curr->prev;
    }
}

/*Prints list using << operator*/
ostream & operator<<(ostream &out, const IntList &rhs){
    IntNode *curr = rhs.dummyHead->next;
    while(curr != rhs.dummyTail){
        if(curr->next == rhs.dummyTail){
            out << curr->data;
        } else {
            out << curr->data << " ";
        }
        curr = curr->next;
    }
    return out;
}
