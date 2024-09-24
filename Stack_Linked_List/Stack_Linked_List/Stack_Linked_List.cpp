// Stack_Linked_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using std::cout;
using std::endl;

class StackList;

class StackNode {
private:
    int data;
    StackNode *next;
public:
    StackNode() :data(0) {
        next = 0;
    }
    StackNode(int x) : data(x) {
        next = 0;
    }
    StackNode(int x, StackNode* nextNode) :data(x), next(nextNode) {};
    friend class StackList;
};

class StackList {
private:
    StackNode* top;
    int size;
public:
    StackList() :size(0), top(0) {};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackList::Push(int x) {

    if (IsEmpty()) {
        top = new StackNode(x);
        size++;
        return;
    }
    StackNode* newnode = new StackNode(x);
    newnode->next = top;
    //StackNode* newnode = new StackNode(x, top);
    top = newnode;
    size++;
}

void StackList::Pop() {

    if (IsEmpty()) {
        cout << "Stack is empty. \n";
        return;
    }

    StackNode* deletenode = top;
    top = top->next;
    delete deletenode;
    deletenode = 0;
    size--;
}

bool StackList::IsEmpty() {

    return (size == 0);
}

int StackList::Top() {
    if (IsEmpty()) {
        cout << "Stack is empty. \n";
        return -1;
    }
    return top->data;
}

int StackList::getSize() {
    return size;
}

int main()
{
    StackList s;
    s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Push(15);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;

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
