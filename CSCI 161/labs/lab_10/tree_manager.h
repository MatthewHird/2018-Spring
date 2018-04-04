#pragma once
#include <iostream>
#include <fstream>
#include "family_tree.h"
#include "stack.h"


class TreeManager
{
public:
    TreeManager();
    ~TreeManager();

    void run();
    void load();

    std::ifstream fin;
    std::string save_file = "MyFamily.txt";
    Stack stack;
    FamilyTree tree;
};