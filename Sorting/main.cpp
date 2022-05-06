#include "Sort.hpp"
#include <iostream>
using namespace std;
int *generateArray(int size) {
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  return array;
}
void printArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
int main() {
  int *array = generateArray(10);
  printArray(array, 10);
  Sort *sort = new Sort();
  sort->shellSort(array, 10);
  printArray(array, 10);
}
