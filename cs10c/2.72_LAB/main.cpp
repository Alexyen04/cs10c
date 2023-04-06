#include <iostream>
#include "IntList.h"


using namespace std;

int main(){
    int testCase = 0;
    cout << "Enter test case 1-5:"; cin >> testCase; cout << endl;
    
    if(testCase == 1){
        IntList test1;
        test1.push_back(1);
        test1.push_back(2);
        test1.push_back(3);
        test1.push_back(4);
        test1.push_back(5);
        cout << "Should print '1 2 3 4 5'" << " Output: " << test1 << endl;
        test1.push_front(6);
        cout << "Should print '6 1 2 3 4 5'" << " Output: " << test1 << endl;
    } else if (testCase == 2){
        IntList test2;
        test2.push_back(1);
        test2.push_back(2);
        test2.push_back(3);
        test2.push_back(4);
        test2.push_back(5);
        test2.push_back(6);
        test2.pop_front();
        test2.pop_back();
        cout << "Should print '2 3 4 5'" << " Output: " << test2 << endl;
    } else if (testCase == 3){
        IntList test3;
        test3.push_back(1);
        test3.push_back(2);
        test3.push_back(3);
        test3.push_back(4);
        test3.push_back(5);
        test3.push_back(6);
        cout << "Should print '6 5 4 3 2 1' " << "Output: ";
        test3.printReverse(); 
        cout << endl;
    }
    
    return 0;
}