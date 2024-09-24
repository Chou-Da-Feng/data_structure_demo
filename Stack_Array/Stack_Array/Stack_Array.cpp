// Stack_Array.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using std::cout;
using std::endl;

class StackArray {
private:
    int top;
    int capacity;
    int *stack;
    void DoubleCapacity();
public:
    StackArray() :top(-1), capacity(1) {                        //初始化變數 top=-1,capacity=1
        stack = new int[capacity];                              //使用new動態分配記憶體
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackArray::DoubleCapacity() {

    capacity *= 2;                                         //加倍容量
    int* newStack = new int[capacity];                     //分配新陣列

    for (int i = 0; i < capacity / 2; i++) {               //複製元素到新陣列中
        newStack[i] = stack[i];
    }

    delete[] stack;                                        //釋放原陣列記憶體空間
    stack = newStack;                                      //更新指標
}

void StackArray::Push(int x) {
    
    if (top == capacity - 1) {                            //檢查陣列是否已滿，如果滿了就增加
        DoubleCapacity();
    }
    stack[++top] = x;                                     //先把top+1再把stack[top+1]的位置加入x (++top)
}

void StackArray::Pop() {

    if (IsEmpty()) {
        cout << "Stack is empty. \n";
        return;
    }
    top--;
//    stack[top] = 0;
//    stack[top].~T();
}

bool StackArray::IsEmpty() {

    //if (top == -1) {
    //    return true;
    //}
    //else {
    //    return false;
    //}

    return (top == -1);
}

int StackArray::Top() {

    if (IsEmpty()) {
        cout << "Stack is empty. \n";
        return -1;
    }
    return stack[top];
}

int StackArray::getSize() {

    return top + 1;
}

int main()
{
    StackArray s;
    s.Pop();
    s.Push(14);
    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Push(7);
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
