//
// Created by SuperUser on 29.05.2024.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <tuple>


enum BinarySearchTreePrintOrder
{
    PREORDER = 0,
    INORDER = 1,
    POSTORDER = 2
};

class BinarySearchTree {
private:
    int value;
    BinarySearchTree* left;
    BinarySearchTree* right;
    BinarySearchTree();

    // Returns (parent, child) tuple. If not found, returns both null.
    std::tuple<BinarySearchTree*, BinarySearchTree*> FindWithParent(BinarySearchTree* parent, int value);
    std::tuple<BinarySearchTree*, BinarySearchTree*> FindBiggestWithParent(BinarySearchTree* parent);
    BinarySearchTree* Insert(BinarySearchTree* root, int value);
    BinarySearchTree* Delete(BinarySearchTree* root, BinarySearchTree* parent, BinarySearchTree* value);
    void ReplaceChild(BinarySearchTree* child, BinarySearchTree* replacement);
    static void PrintNode(BinarySearchTree* node);
    void PrintInner(BinarySearchTreePrintOrder order);

public:
    BinarySearchTree(int value);
    ~BinarySearchTree();

    int GetValue();

    BinarySearchTree* Insert(int value);
    BinarySearchTree* Find(int value);
    BinarySearchTree* FindBiggest();
    BinarySearchTree* Delete(int value);

    void Print(BinarySearchTreePrintOrder order);

};



#endif //BINARY_SEARCH_TREE_H
