// Queue_Circular.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using std::cout;

class QueueArrayCircular {
private:
    int capacity, front, back;
    int* queue;
    void DoubleCapacity();
public:
    QueueArrayCircular() :capacity(5), front(0), back(0) {     // 從0開始, 第一個位置放掉
        queue = new int[capacity];
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    bool IsFull();
    int getFront();
    int getBack();
    int getSize();
    int getCapacity();    // 驗證用, 可有可無
};

void QueueArrayCircular::DoubleCapacity() {

    int* newQueue = new int[capacity * 2];

    int j = front, size = getSize();
    for (int i = 1; i <= size; i++) {
        newQueue[i] = queue[++j % capacity];    // j 要先加一, 因為 front 沒有東西
    }

    back = getSize();   // 要在更改 capacity 之前抓住 back
    front = 0;          // 改變 front 要在 getSize() 之後
    capacity *= 2;

    delete[] queue;
    queue = newQueue;
}
void QueueArrayCircular::Push(int x) {

    if (IsFull()) {
        DoubleCapacity();
    }

    back = (back + 1) % capacity;
    queue[back] = x;
}
void QueueArrayCircular::Pop() {

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    front = (front + 1) % capacity;
}
bool QueueArrayCircular::IsEmpty() {

    return (front == back);
}
bool QueueArrayCircular::IsFull() {

    return ((back + 1) % capacity == front);
}
int QueueArrayCircular::getFront() {

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return queue[(front + 1) % capacity];
}
int QueueArrayCircular::getBack() {

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return queue[back];
}
int QueueArrayCircular::getSize() {

    int size;
    if (front < back) {
        size = back - front;
    }
    else {
        size = capacity - (front - back);
    }

    return size;
}
int QueueArrayCircular::getCapacity() {

    return capacity;
}

void printCircularQueue(QueueArrayCircular queue) {
    cout << "front: " << queue.getFront() << "    back: " << queue.getBack() << "\n"
        << "capacity: " << queue.getCapacity() << "  number of elements: " << queue.getSize() << "\n\n";
}

int main() {

    QueueArrayCircular q;
    if (q.IsEmpty()) {
        cout << "Queue is empty.\n\n";
    }
    q.Push(24);
    cout << "After push 24:\n";
    printCircularQueue(q);
    q.Push(8);
    q.Push(23);
    cout << "After push 8, 23:\n";
    printCircularQueue(q);
    q.Pop();
    cout << "After pop 24:\n";
    printCircularQueue(q);
    q.Push(13);
    cout << "After push 13:\n";
    printCircularQueue(q);
    q.Pop();
    cout << "After pop 8:\n";
    printCircularQueue(q);
    q.Push(35);
    cout << "After push 35:\n";
    printCircularQueue(q);
    q.Push(9);
    cout << "After push 9:\n";
    printCircularQueue(q);
    q.Push(64);
    cout << "After push 64:\n";
    printCircularQueue(q);
    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
