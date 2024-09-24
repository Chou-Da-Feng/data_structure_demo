// Stack_MinStack.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>        // std::stack<>

class MinStack {
private:
    std::stack<int> data;
    std::stack<int> minstack;
public:
    MinStack() {};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
    int getMin();
};
void MinStack::Push(int x) {

    data.push(x);
    if (minstack.empty() || x < minstack.top()) {
        minstack.push(x);
    }
    else {
        minstack.push(minstack.top());
    }
}

void MinStack::Pop() {

    if (data.empty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    data.pop();
    minstack.pop();
}

int MinStack::getMin() {

    if (data.empty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }

    return minstack.top();
}

bool MinStack::IsEmpty() {

    return data.empty();
}

int MinStack::Top() {

    if (data.empty()) {
        std::cout << "Stack is empty.\n";   // sorry for the bad exception handling
        return -1;
    }

    return data.top();
}

int MinStack::getSize() {

    if (data.empty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }

    return (int)data.size();
}

int main() {

    MinStack s;
    s.Pop();
    s.Push(6);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(13);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(1);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

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
