class Sort {
public:
  void swapSort(int *array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (array[i] > array[j]) {
          temp = array[j];
          array[j] = array[i];
          array[i] = temp;
        }
      }
    }
  }
  void selectionSort(int *array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
      int min = i;
      for (int j = i + 1; j < size; j++) {
        if (array[j] < array[min]) {
          min = j;
        }
      }
      temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }
  }
  void insertionSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
      int j = 0;
      while (j < i) {
        if (array[i] < array[j]) {
          int temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
        j++;
      }
    }
  }
  void bubbleSort(int *array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (array[j] > array[j + 1]) {
          temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
      }
    }
  }
};