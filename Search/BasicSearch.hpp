#include <iostream>
using namespace std;
class BasicSearch {
public:
  int linearSearch(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
      if (array[i] == value) {
        return i;
      }
    }
    return -1;
  }
  int binarySearch(int *array, int size, int value) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (array[mid] == value) {
        return mid;
      } else if (array[mid] < value) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
};