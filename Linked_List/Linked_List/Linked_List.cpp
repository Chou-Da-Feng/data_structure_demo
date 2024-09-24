// Linked_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using std::cout;
using std::endl;

class LinkedList;

class ListNode {
private:
    int data;
    ListNode* next;
public:
    ListNode() :data(0), next(0) {};
    ListNode(int a) :data(a), next(0) {};

    friend class LinkedList;
};


class LinkedList {
private:
    int size;
    ListNode* first;
public:
    LinkedList() :first(0) {};
    void PrintList();
    void Push_front(int x);
    void Push_back(int x);
    void Delete(int x);
    void Clear();
    void Reverse();
};

// PrintList

void LinkedList::PrintList() {
    if (first == 0) {
        cout << "List is empty.\n";
        return;
    }
    ListNode* current = first;
    while (current != 0) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Push_front
void LinkedList::Push_front(int x) {

    ListNode* newNode = new ListNode(x); //配置新記憶體
    newNode->next = first;               //儲存原本first的address
    first = newNode;                     //再把first更新成新的data
}

// Push_back
void LinkedList::Push_back(int x) {

    ListNode* newNode = new ListNode(x);  //配置新記憶體

    if (first == 0) {                     //如果list沒有node，令NewNode為first
        first = newNode;
        return;
    }

    ListNode* current = first;               //遍歷所有Node，直到current為最後一個Node
    while (current->next != 0) {
        current = current->next;
    }
    current->next = newNode;               //將最後一個node的address，從NULL更新為newNode
}

//Delete
void LinkedList::Delete(int x) {
    ListNode* current = first;
    ListNode* previous = 0;

    while (current != 0 && current->data != x) {     //list不是empty 與 還未找到要刪除的資料就遍歷list
        previous = current;
        current = current->next;
    }

    if (current == 0) {                              //list為empty或是沒有要刪除的node
        cout << "There is no " << x << " in list.\n";
        //return;
    }
    else if (current == first) {                     //要刪除的資料室開頭第一個
        first = current->next;
        delete current;
        current = 0;
        //return;
    }
    else {
        previous->next = current->next;               //其餘條件，有找到要刪除的資料，資料在list中
        delete current;
        current = 0;
        //return;
    }
}

//Clear
void LinkedList::Clear() {

    while (first != 0) {
        ListNode* current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}

//Reverse

void LinkedList::Reverse() {

    if (first == 0 || first->next == 0) {
        cout << "list is empty or list has only one node.\n";
        return;
    }

    ListNode* previous = 0,
        * current = first,
        * preceding = first->next;

    while (preceding != 0) {
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next;
    }

    current->next = previous;
    first = current;

}


int main() {
    LinkedList list;     // 建立LinkedList的object
    list.PrintList();    // 目前list是空的
    list.Delete(4);      // list是空的, 沒有4
    list.Push_back(5);   // list: 5
    list.Push_back(3);   // list: 5 3
    list.Push_front(9);  // list: 9 5 3
    list.PrintList();    // 印出:  9 5 3
    list.Push_back(4);   // list: 9 5 3 4
    list.Delete(9);      // list: 5 3 4
    list.PrintList();    // 印出:  5 3 4
    list.Push_front(8);  // list: 8 5 3 4
    list.PrintList();    // 印出:  8 5 3 4
    list.Reverse();      // list: 4 3 5 8
    list.PrintList();    // 印出:  4 3 5 8
    list.Clear();        // 清空list
    list.PrintList();    // 印出: List is empty.

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
