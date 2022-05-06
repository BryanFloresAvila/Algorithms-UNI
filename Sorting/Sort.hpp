using namespace std;
class Sort {
public:
  void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
  }

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
  void shellSort(int *array, int n) {
    bool cambio;
    int s = n / 2, rec = 0;
    while (s >= 1) {
      cambio = true; // Hubo cambios
      while (cambio) {
        cambio = false;
        for (int i = 0; i < n - s; i++)
          if (array[i] > array[i + s]) {
            swap(array[i], array[i + s]);
            cambio = true;
          }
      }
      s /= 2;
    }
  }
  void quickSort(int array[], int inicio, int fin) {
    int i, j, central; // indices
    int pivote;
    central = (inicio + fin) / 2;
    pivote = array[central];
    i = inicio;
    j = fin;
    while (i <= j) {
      while (array[i] < pivote)
        i++;
      while (array[j] > pivote)
        j--;
      if (i <= j) {
        swap(array[i], array[j]);
        i++;
        j--;
      }
    }
    if (inicio < j)
      quickSort(array, inicio, j);
    if (i < fin)
      quickSort(array, i, fin);
  }
};