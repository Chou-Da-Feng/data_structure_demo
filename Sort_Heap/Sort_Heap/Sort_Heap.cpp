// Sort_Heap.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

void swap(int& p1, int& p2) {
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void MaxHeapify(std::vector<int>& array, int root, int length) {
    int left = 2 * root;
    int right = 2 * root + 1;
    int largest;

    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if (right <= length && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        swap(array[largest], array[root]);
        MaxHeapify(array, largest, length);
    }
}

void BuildMaxHeap(std::vector<int>& array) {
    for (int i = (int)array.size() / 2; i >= 1; i--) {
        MaxHeapify(array, i, (int)array.size() - 1);
    }
}

void HeapSort(std::vector<int>& array) {
    array.insert(array.begin(), 0);

    BuildMaxHeap(array);

    int size = (int)array.size() - 1;
    for (int i = (int)array.size() - 1; i >= 2; i--) {
        swap(array[1], array[i]);
        size--;
        MaxHeapify(array, 1, size);
    }

    array.erase(array.begin());
}

void PrintArray(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> array = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };

    std::cout << "original:\n";
    PrintArray(array);

    HeapSort(array);

    std::cout << "sorted:\n";
    PrintArray(array);

    return 0;
}

