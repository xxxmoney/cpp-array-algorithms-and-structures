#include <iostream>

#include "binary_search_tree.h"
#include "heap_sort.h"
#include "linked_list.h"
#include "linked_list_double.h"
#include "merge_sort.h"
#include "queue.h"
#include "quick_sort.h"
#include "stack.h"
#include "tree.h"

void TestLinkedList()
{
    LinkedList* first = new LinkedList(5);
    LinkedList* last = first->SetNext(10)->SetNext(45)->SetNext(1)->SetNext(10);
    first->Print();

    LinkedList* second = first->GetNext();
    LinkedList* third = second->InsertAfter(4);
    first->Print();

    third = third->RemoveAfter();
    first->Print();

    first = first->RemoveBefore(nullptr);
    first->Print();

    delete first;
}

void TestDoubleLinkedList()
{
    LinkedListDouble* first = new LinkedListDouble(4);
    LinkedListDouble* last = first->InsertAfter(7)->InsertAfter(11)->InsertAfter(1)->InsertAfter(69);
    first->Print();

    LinkedListDouble* middle = first->GetNext()->GetNext();
    LinkedListDouble* found = middle->FindFirst(69);
    std::cout << "Found: " << found->GetValue() << std::endl;
    found = middle->FindFirst(300);
    std::cout << "Found: " << found->GetValue() << std::endl;

    LinkedListDouble* third = first->GetNext()->GetNext()->RemoveAfter();
    first->Print();

    third = third->InsertBefore(20);
    first->Print();

    third->InsertAfter(420);
    first->Print();

    last->RemoveBefore();
    first->Print();

    first = first->GetNext()->RemoveBefore();
    first->Print();

    last = last->GetPrevious()->RemoveAfter();
    first->Print();

    delete first;
}

void TestStack()
{
    Stack stack = Stack(10);

    stack.Push(4);
    stack.Push(10);
    stack.Push(69);
    stack.Push(7);

    stack.Print();

    std::cout << stack.Pop() << std::endl;

    stack.Print();

    std::cout << stack.Peek() << std::endl;

    stack.Print();

    std::cout << stack.IsEmpty() << std::endl;
}

void TestQueue()
{
    Queue queue = Queue(10);

    queue.Enqueue(4);
    queue.Enqueue(10);
    queue.Enqueue(69);
    queue.Enqueue(7);

    queue.Print();

    std::cout << "Dequeued: " << queue.Dequeue() << std::endl;

    queue.Print();
}

void TestBinarySearchTree()
{
    BinarySearchTree* tree = new BinarySearchTree(40);

    tree->Insert(21)->Insert(48)->Insert(9)->Insert(61)->Insert(33)->Insert(30)->Insert(4)->Insert(17)->Insert(53)->Insert(77);

    tree->Print(BinarySearchTreePrintOrder::PREORDER);

    BinarySearchTree* item = tree->Find(30);
    std::cout << "Found: " << item->GetValue() << std::endl;
    item = tree->Find(17);
    std::cout << "Found: " << item->GetValue() << std::endl;
    item = tree->Find(77);
    std::cout << "Found: " << item->GetValue() << std::endl;
    item = tree->Find(666);
    std::cout << "Found: " << item << std::endl;
    item = tree->FindBiggest();
    std::cout << "Biggest: " << item->GetValue() << std::endl;

    int toRemove = 77;
    tree = tree->Delete(toRemove);
    std::cout << "Removed: " << toRemove << std::endl;
    tree->Print(BinarySearchTreePrintOrder::PREORDER);

    toRemove = 61;
    tree = tree->Delete(toRemove);
    std::cout << "Removed: " << toRemove << std::endl;
    tree->Print(BinarySearchTreePrintOrder::PREORDER);

    toRemove = 21;
    tree = tree->Delete(toRemove);
    std::cout << "Removed: " << toRemove << std::endl;
    tree->Print(BinarySearchTreePrintOrder::PREORDER);
}

void TestTree()
{
    Tree* tree = new Tree(10);
    tree->Insert(4)->Insert(5)->Insert(8);
    tree->GetChildren()[0]->Insert(7)->Insert(20);
    tree->GetChildren()[1]->Insert(55);

    Tree* item = tree->Find(10);
    std::cout << "Found: " << item->GetValue() << std::endl;
    item = tree->Find(7);
    std::cout << "Found: " << item->GetValue() << std::endl;

    tree->Print();

}

void TestQuickSort()
{
    std::vector<int> items = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    QuickSort sort = QuickSort(items);

    sort.Sort();
    sort.Print();
}

void TestMergeSort()
{
    std::vector<int> items = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    MergeSort sort = MergeSort(items);

    sort.Sort();
    sort.Print();
}

void TestHeapSort()
{
    std::vector<int> items = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    HeapSort sort = HeapSort(items);

    sort.Sort();
    sort.Print();
}

int main()
{
    //TestLinkedList();
    //TestDoubleLinkedList();
    //TestStack();
    //TestQueue();
    //TestBinarySearchTree();
    //TestTree();
    //TestQuickSort();
    //TestMergeSort();
    TestHeapSort();

    return 0;
}
