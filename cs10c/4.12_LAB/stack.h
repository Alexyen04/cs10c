#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

// This is a generic stack class template
template <typename T> 
class stack {
    public:
        // Default constructor
        stack();

        // Adds a value to the stack
        void push(T val);

        // Removes the top value from the stack
        void pop();

        // Removes the two top values from the stack
        void pop_two();

        // Returns the top value of the stack
        T top();

        // Returns true if the stack is empty, false otherwise
        bool empty();
    private: 
        // Maximum size of the stack
        static const int MAX_SIZE = 20;

        // Current size of the stack
        int size;

        // Data stored in the stack
        T data [MAX_SIZE];
};

template <typename T> stack<T>::stack() {
    // Initialize size to 0
    size = 0; 
}

template <typename T> void stack<T>::push(T val){
    // Check if stack is full
    if(size == 20){
        // Throw an overflow error if stack is full
        throw overflow_error ("Called push on full stack.");
    } else {
        // Add the value to the top of the stack
        data[size] = val;
        // Increment the size
        size++;
    }
}

template <typename T> void stack<T>::pop(){
    // Check if stack is empty
    if(empty()){
        // Throw an out_of_range error if stack is empty
        throw out_of_range ("Called pop on empty stack.");
    } else {
        // Decrement the size
        size--; 
    }
}

template <typename T> void stack<T>::pop_two(){
    // Check if stack is empty
    if(empty()){
        // Throw an out_of_range error if stack is empty
        throw out_of_range ("Called pop_two on empty stack.");
    } else if (size == 1){
        // Throw an out_of_range error if stack size is 1
        throw out_of_range ("Called pop_two on a stack of size 1.");
    } else {
        // Remove the two top values from the stack
        size = size-2;
    }
}

template <typename T> T stack<T>::top() {
    // Check if stack is empty
    if(empty()){
        // Throw an underflow error if stack is empty
        throw underflow_error ("Called top on empty stack.");
    }
    // Return the top value of the stack
    return data[size-1];
}

template <typename T> bool stack<T>::empty() {
    // Return true if the stack size is 0, false otherwise
    return (size == 0);
}

#endif 
