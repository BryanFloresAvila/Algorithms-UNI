#include <cmath>
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

  void mezclaLista(int vector[], int izq, int cen, int der) {
    int *temporal = new int[der + 1];
    int i, j, k;
    i = k = izq;
    j = cen + 1;
    while (i <= cen && j <= der) {
      if (vector[i] < vector[j]) {
        temporal[k] = vector[i];
        i++;
        k++;
      } else {
        temporal[k] = vector[j];
        j++;
        k++;
      }
    }
    while (i <= cen)
      temporal[k++] = vector[i++];
    while (j <= der)
      temporal[k++] = vector[j++];
    // Copiando el temporal al vector
    for (int k = izq; k <= der; k++)
      vector[k] = temporal[k];
  }

  void mergeSort(int vector[], int izq, int der) {
    int cen;
    if (izq < der) {
      cen = (izq + der) / 2;
      mergeSort(vector, izq, cen);
      mergeSort(vector, cen + 1, der);
      mezclaLista(vector, izq, cen, der);
    } else
      return;
  }

  void heapSort(int vector[], int n) {
    // Posición del último padre i = (n-1)/2
    // Posición del hijo izquierdo = 2i+1
    // Posición del hijo derecho = 2i+2
    int i, izq, der, hi, hd;
    for (n = n; n > 1; n--) {
      i = (n - 1) / 2;
      while (i >= 0) {
        hi = 2 * i + 1;
        hd = 2 * i + 2;
        if (hd < n) {
          if (vector[hd] > vector[i] && vector[hd] >= vector[hi])
            swap(vector[hd], vector[i]);
          else if (vector[hi] > vector[i] && vector[hi] >= vector[hd])
            swap(vector[hi], vector[i]);
        } else if (hi < n)
          if (vector[hi] > vector[i])
            swap(vector[hi], vector[i]);
        i--;
      }
      swap(vector[0], vector[n - 1]);
    }
  }

  void radixSort(int vector[], int n) {
    int i, max, digMax = 0, p = 0, dig, j, k;
    int c[10]{};                  // Vector que cuenta las columnas en la matriz
    int **matriz = new int *[10]; // Crea la matriz
    for (i = 0; i < 10; i++)
      matriz[i] = new int[n]{};
    // Hallando el maximo
    max = vector[0];
    for (i = 1; i < n; i++)
      if (vector[i] > max)
        max = vector[i];
    // Hallando la cantidad de digitos del maximo
    while (max > 0) {
      max = max / 10;
      digMax++;
    }
    // Algoritmo Heap
    while (p < digMax) {
      // Moviendo los numeros del vector a la matriz
      for (i = 0; i < n; i++) {
        dig = vector[i] / (int)pow(10, p) % 10;
        matriz[dig][c[dig]] = vector[i];
        c[dig]++;
      }
      // Subiendo la matriz al vector
      k = 0;
      for (i = 0; i < 10; i++) {
        for (j = 0; j < c[i]; j++)
          vector[k++] = matriz[i][j];
        c[i] = 0;
      }
      p++;
    }
  }
};
