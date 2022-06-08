#include<iostream>
#include "DoubleList.hpp"
using namespace std;

int main(){
    DoubleList dl;
    dl.createList();
    dl.printList();
    dl.sortList();
    dl.printList();
    return 0;
}