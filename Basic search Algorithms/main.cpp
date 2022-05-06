#include <iostream>
#include "BasicSearch.hpp"
using namespace std;

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 5;
    BasicSearch bs;
    int index = bs.linearSearch(array, size, value);
    cout << "The index of " << value << " is " << index << endl;
    index = bs.binarySearch(array, size, value);
    cout << "The index of " << value << " is " << index << endl;
    return 0;
}