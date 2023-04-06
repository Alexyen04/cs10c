#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/*Passes in an index of type int and a vector of type T (T could be string, double or int).
The function returns the index of the min value starting from "index" to the end of the "vector".*/
template <typename T> 
unsigned min_index(const vector<T> &vals, unsigned index){
    int minimum = index;
    while(index < vals.size()){
        if(vals[index] < vals[minimum]){
            minimum = index;
        }
        index++;
    }
    return minimum;
}

/*Passes in a vector of type T and sorts them based on the selection sort method.
This function should utilize the min_index function to find the index of the min value in the unsorted portion of the vector.*/
template <typename T>
void selection_sort(vector<T> &vals){
    for(unsigned int i = 0; i < vals.size(); i++){
        swap(vals[i], vals[min_index(vals, i)]);
    }
}

/*Passes in a vector of type T (T could be string, double or int) and an index of type int.
The function returns the element located at the index of the vals.*/
template <typename T>
T getElement(vector<T> vals, unsigned int index){
    if(index < 0 || index > vals.size()){
        throw out_of_range("out of range exception occured");
    }
    return vals.at(index);
}

/*Creates char vector of random size*/
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <typename T> 
void print(const vector <T> &vals){
    for(unsigned int i = 0; i < vals.size(); i ++){
        cout << vals.at(i) << " ";
    }
    cout << endl;
}



int main(){
    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    // while(--numOfRuns >= 0){
    //     cout << "Enter a number: " << endl;
    //     cin >> index;
    //     try {
    //     curChar = getElement(vals,index);
    //     cout << "Element located at " << index << ": is " << curChar << endl;
    //     }
    //     catch (out_of_range &except){
    //         cout << except.what() << endl;
    //     }
    // }

    vector <int> test1 {-9,3,7,9,2,6,7,1,-23};
    vector <double> test2 {5.3,7.8,2.3,-6.5,3.3,4.5,-2.9,2.1};
    vector <string> test3 {"three", "six", "nine", "one", "zero", "seven", "eight"};

    {//test cases for minIndex
        if(min_index(test1, 0) != 8) {cout << "test1 'minIndex' failed" << endl;}
        //cout << "test1: " << min_index(test1, 0) << endl;
        if(min_index(test2, 0) != 3) {cout << "test2 'minIndex' failed" << endl;}
        //cout << "test2: " << min_index(test2, 0) << endl;
        if(min_index(test3, 0) != 6) {cout << "test3 'minIndex' failed" << endl;}
        //cout << "test3: " << min_index(test3, 0) << endl;

        if(min_index(test1, 5) != 8) {cout << "test1 'minIndex' failed" << endl;}
        //cout << "test1: " << min_index(test1, 5) << endl;
        if(min_index(test2, 4) != 6) {cout << "test2 'minIndex' failed" << endl;}
        //cout << "test2: " << min_index(test2, 4) << endl;
        if(min_index(test3, 2) != 6) {cout << "test3 'minIndex' failed" << endl;}
        //cout << "test3: " << min_index(test3, 2) << endl;
    }

    {//test cases for selectionSort
        selection_sort(test1);
        print(test1);
        unsigned int i = 0;
        while(i < test1.size()-1){
            if(test1[i] > test1[i+1]) { cout << "test1 'selection_sort' failed" << endl;}
            i++;
        }
        selection_sort(test2);
        print(test2);
        i = 0;
        while(i < test2.size()-1){
            if(test2[i] > test2[i+1]) { cout << "test2 'selection_sort' failed" << endl;}
            i++;
        }
        selection_sort(test3);
        print(test3);
        i = 0; 
        while(i < test3.size()-1){
            if(test3[i] > test3[i+1]) { cout << "test3 'selection_sort' failed" << endl;}
            i++;
        }
    }
    
    return 0;
}
