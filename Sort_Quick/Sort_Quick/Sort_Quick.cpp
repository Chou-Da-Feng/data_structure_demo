// Sort_Quick.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int* arr, int front, int end) {
    int pivot = arr[end];
    int i = front - 1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int* arr, int front, int end) {
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1); //排列pivot左邊數列
        QuickSort(arr, pivot + 1, end); //排列pivot右邊數列
    }
}
void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {

    int n = 9;
    int arr[] = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
    std::cout << "original:\n";
    PrintArray(arr, n);

    QuickSort(arr, 0, n - 1);

    std::cout << "sorted:\n";
    PrintArray(arr, n);
    return 0;
}
