//
// Created by SuperUser on 29.05.2024.
//

#include "binary_search_tree.h"

#include <iostream>

BinarySearchTree::BinarySearchTree(int value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    BinarySearchTree* left = this->left;
    BinarySearchTree* right = this->right;

    delete left;
    delete right;
}


int BinarySearchTree::GetValue()
{
    return this->value;
}


BinarySearchTree* BinarySearchTree::Insert(BinarySearchTree* root, int value)
{
    if(value < this->value)
    {
        if(this->left == nullptr)
        {
            this->left = new BinarySearchTree(value);
            return root;
        }

        return this->left->Insert(root, value);
    }
    if(this->right == nullptr)
    {
        this->right = new BinarySearchTree(value);
        return root;
    }

    return this->right->Insert(root, value);
}


BinarySearchTree* BinarySearchTree::Insert(int value)
{
    return this->Insert(this, value);
}

std::tuple<BinarySearchTree*, BinarySearchTree*> BinarySearchTree::FindWithParent(BinarySearchTree* parent, int value)
{
    if(value == this->value)
        return std::tuple(parent, this);
    else if(value < this->value && this->left != nullptr)
        return this->left->FindWithParent(this, value);
    else if(this->right != nullptr)
        return this->right->FindWithParent(this, value);

    return std::tuple(nullptr, nullptr);
}

BinarySearchTree* BinarySearchTree::Find(int value)
{
     return std::get<1>(this->FindWithParent(nullptr, value));
}

std::tuple<BinarySearchTree*, BinarySearchTree*> BinarySearchTree::FindBiggestWithParent(BinarySearchTree* parent)
{
    if(this->right != nullptr)
        return this->right->FindBiggestWithParent(this);

    return std::tuple(parent, this);
}


BinarySearchTree* BinarySearchTree::FindBiggest()
{
    return std::get<1>(FindBiggestWithParent(nullptr));
}


BinarySearchTree* BinarySearchTree::Delete(int value)
{
    std::tuple<BinarySearchTree*, BinarySearchTree*> itemWithParent = FindWithParent(nullptr, value);
    BinarySearchTree* parent = std::get<0>(itemWithParent);
    BinarySearchTree* item = std::get<1>(itemWithParent);

    if(item == nullptr)
        return this;

    // Both exist
    if(item->left != nullptr && item->right != nullptr)
    {
        std::tuple<BinarySearchTree*, BinarySearchTree*> biggestFromLeftWithParent = item->left->FindBiggestWithParent(parent);
        BinarySearchTree* fromLeftParent = std::get<0>(biggestFromLeftWithParent);
        BinarySearchTree* fromLeftItem = std::get<1>(biggestFromLeftWithParent);

        parent->ReplaceChild(item, fromLeftItem);
        fromLeftParent->ReplaceChild(fromLeftItem, nullptr);
        fromLeftItem->left = item->left != fromLeftItem ? item->left : nullptr;
        fromLeftItem->right = item->right;
    }
    // Left or right exists
    else if (item->left != nullptr || item->right != nullptr)
    {
        BinarySearchTree* childReplacement = item->left != nullptr ? item->left : item->right;
        parent->ReplaceChild(item, childReplacement);
    }
    // None exist
    else
        parent->ReplaceChild(item, nullptr);

    item->left = nullptr;
    item->right = nullptr;
    delete item;
    return this;
}

void BinarySearchTree::ReplaceChild(BinarySearchTree* child, BinarySearchTree* replacement)
{
    if(this->left == child)
        this->left = replacement;
    if(this->right == child)
        this->right = replacement;
}


void BinarySearchTree::PrintNode(BinarySearchTree* node)
{
    std::cout << node->value << "\t";
}

void BinarySearchTree::PrintInner(BinarySearchTreePrintOrder order)
{
    if(order == BinarySearchTreePrintOrder::PREORDER)
        PrintNode(this);

    if(this->left != nullptr)
        this->left->PrintInner(order);

    if(order == BinarySearchTreePrintOrder::INORDER)
        PrintNode(this);

    if(this->right != nullptr)
        this->right->PrintInner(order);

    if(order == BinarySearchTreePrintOrder::POSTORDER)
        PrintNode(this);
}


void BinarySearchTree::Print(BinarySearchTreePrintOrder order)
{
    this->PrintInner(order);
    std::cout << std::endl;
}



