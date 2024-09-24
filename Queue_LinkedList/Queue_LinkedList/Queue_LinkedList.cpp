// Queue_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

struct QueueNode {
    int data;
    QueueNode *next;
    QueueNode() :data(0), next(0) {};
    QueueNode(int x) :data(x), next(0) {};
};

class QueueList {
private:
    QueueNode *front;
    QueueNode* back;
    int size;
public:
    QueueList() :front(0), back(0), size(0) {};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int getFront();
    int getBack();
    int getSize();
};

void QueueList::Push(int x) {

    if (IsEmpty()) {
        front = new QueueNode(x);
        back = front;
        size++;
        return;
    }

    QueueNode* newNode = new QueueNode(x);
    back->next = newNode;
    back = newNode;         // update back pointer
    size++;
}

void QueueList::Pop() {

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    QueueNode* deletenode = front;
    front = front->next;    // update front pointer
    delete deletenode;
    deletenode = 0;
    size--;
}


int QueueList::getFront() {

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return front->data;
}

int QueueList::getBack() {

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return back->data;
}

bool QueueList::IsEmpty() {

    //    return (size == 0);
    return ((front && back) == 0);
}

int QueueList::getSize() {

    return size;
}

int main()
{
    QueueList q;
    if (q.IsEmpty()) {
        std::cout << "Queue is empty.\n";
    }
    q.Push(24);
    std::cout << "\nAfter push 24: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(8);
    std::cout << "\nAfter push 8: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(23);
    std::cout << "\nAfter push 23: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Push(13);
    std::cout << "\nAfter push 13: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Push(35);
    std::cout << "\nAfter push 35: \n";
    std::cout << "front: " << q.getFront() << "     back: " << q.getBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    std::cout << "front: " << q.getFront() << "    back: " << q.getBack() << "\n";
    q.Pop();
    std::cout << "\nAfter pop the front element: \n";
    q.Pop();

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
