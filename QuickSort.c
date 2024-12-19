#include <stdio.h>

int quickSort(int arr[], int bas, int son) {
    int pivot = arr[son]; // Pivot olarak son eleman seçiliyor
    int i = bas - 1;      // Küçük elemanların konumunu takip eden değişken

    for (int j = bas; j < son; j++) {
        if (arr[j] < pivot) {
            i++;
            // Elemanları yer değiştir
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Pivot elemanını doğru yerine yerleştir
    int temp = arr[i + 1];
    arr[i + 1] = arr[son];
    arr[son] = temp;

    return i + 1;
}

// Quick Sort algoritması
void quickSort(int arr[], int bas, int son) {
    if (bas < son) {
        // Pivot elemanını bul
        int pi = partition(arr, bas, son);

        // Pivotun solunda ve sağında sıralama işlemini yap
        quickSort(arr, bas, pi - 1);
        quickSort(arr, pi + 1, son);
    }
}
