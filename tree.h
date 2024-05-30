//
// Created by SuperUser on 30.05.2024.
//

#ifndef TREE_H
#define TREE_H
#include <vector>


class Tree {
private:
    int value;
    std::vector<Tree*> children;
    Tree();

public:
    Tree(int value);
    ~Tree();
    std::tuple<Tree*, Tree*> FindWithParent(Tree* parent, int value);

    int GetValue();
    std::vector<Tree*>& GetChildren();

    Tree* Find(int value);
    Tree* Insert(int value);

    void Print();

};



#endif //TREE_H
