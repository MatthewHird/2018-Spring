#pragma once
#include <iostream>
#include "person.h"


class FamilyTree
{
public:
    FamilyTree();
    ~FamilyTree();
    
    void insert_root(Person* person);
    void insert(Person* parent, Person* child);
    void preorder();
    void postorder();

private:
    void delete_all(Person* person);
    void traverse(Person* person, int order);
    Person* root;
};