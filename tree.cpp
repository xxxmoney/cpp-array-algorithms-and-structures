//
// Created by SuperUser on 30.05.2024.
//

#include "tree.h"
#include <algorithm>
#include <iostream>

Tree::Tree()
{
    this->value = 0;
}

Tree::Tree(int value)
{
    this->value = value;
}

Tree::~Tree()
{
    for (auto* element : this->children)
    {
        delete element;
    }
    this->children.clear();
}

int Tree::GetValue()
{
    return this->value;
}


std::vector<Tree*>& Tree::GetChildren()
{
    return this->children;
}


std::tuple<Tree*, Tree*> Tree::FindWithParent(Tree* parent, int value)
{
    if(this->value == value)
        return std::tuple(parent, this);

    Tree* result = nullptr;
    for (auto& element : this->children)
    {
        result = element->Find(value);
        if(result)
            return std::tuple(this, element);
    }

    return std::tuple(nullptr, nullptr);
}

Tree* Tree::Find(int value)
{
    return std::get<1>(this->FindWithParent(nullptr, value));
}

Tree* Tree::Insert(int value)
{
    this->children.push_back(new Tree(value));
    return this;
}

void Tree::Print()
{
    std::cout << this->value << ":" << std::endl;
    for (auto* element : this->children)
    {
        std::cout << element->value << "\t";
    }

    std::cout << std::endl;

    for (auto* element : this->children)
    {
        element->Print();
    }
}




