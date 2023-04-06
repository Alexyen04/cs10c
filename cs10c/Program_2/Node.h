#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node{
    public:
        Node();
        ~Node();
        Node(string s);
        void setCount(int);
        int getCount();       
        void increaseCount();
        void decreaseCount();
        string getLabel();
        void setLabel(string);
        Node* getLeftNode();
        void setLeftNode(Node*);
        Node* getRightNode();
        void setRightNode(Node*);
    private:
        int count;
        string label;
        Node *leftNode;
        Node *rightNode;
};

#endif