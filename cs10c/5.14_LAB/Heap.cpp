#include "Heap.h"
#include <iostream>

using namespace std;


Heap::Heap(){
    numItems = 0; //empty heap
}

void Heap::enqueue(PrintJob *job){
    if(numItems == MAX_HEAP_SIZE){ //Exits function if heap is full
        return;
    } else if (numItems == 0){ //empty heap case
        arr[0] = job;
        numItems++;
    } else { //Adds value to end of array and percolates up to proper position
        arr[numItems] = job;
        numItems++;
        trickleUp(numItems-1);
    }
}

void Heap::dequeue(){
    if(numItems == 0 || numItems == 1){ //if empty or only root
        numItems = 0; 
        return;
    } else {
        swap(arr[0], arr[numItems-1]); //moves last node to root
        numItems--; 
        trickleDown(0); //percolates node down
    }   
}

PrintJob* Heap::highest(){
    if(numItems > 0){
        return arr[0];
    } else {return NULL;} //Null if heap is empty
}

void Heap::print(){
    cout << "Priority: " << arr[0]->getPriority() << ", "
        << "Job Number: " << arr[0]->getJobNumber() << ", "
        << "Number of Pages: " << arr[0]->getPages()
        << endl;
}

void Heap::trickleDown(int currentIndex){
    int childIndex = 2*currentIndex + 1; //child node of the index node
    int currentValue = arr[currentIndex]->getPriority();

    while(childIndex < numItems){
        //Index and values for largest node
        int maxValue = currentValue;
        int maxIndex = childIndex;
        for(int i = 0; i < 2 && i+childIndex < numItems; i++){ // Finds largest child node, assigns its index and value to variables
            if(maxValue < arr[childIndex + i]->getPriority()){
                maxValue = arr[childIndex + i]->getPriority();
                maxIndex = childIndex + i;
            }
        }

        if(maxValue == currentValue) { //if the current value is already the largest, exits function 
            return;
        } else { //swaps the root with highest node
            swap(arr[maxIndex], arr[currentIndex]);
            currentIndex = maxIndex;
            childIndex = currentIndex*2 + 1;
        }
    }
}

void Heap::trickleUp(int currentIndex){
    while(currentIndex > 0){
        int parentIndex = (currentIndex-1) / 2; //index for parent
        if(arr[currentIndex]->getPriority() <= arr[parentIndex]->getPriority()){ //if new node added is smaller/equal, keeps position
            return;
        } else { //percolates new node up, switching with parent node
            swap(arr[currentIndex], arr[parentIndex]);
            currentIndex = parentIndex; 
        }
    }
}

