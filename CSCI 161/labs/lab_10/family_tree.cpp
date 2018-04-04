#include "family_tree.h"
#include "person.h"
#include <iostream>


FamilyTree::FamilyTree()
{
    root = nullptr;
}


FamilyTree::~FamilyTree()
{}


void FamilyTree::insert_root(Person* person)
{
    root = person;
}


void FamilyTree::insert(Person* parent, Person* child)
{
    parent->children[parent->child_count] = child;
    parent->child_count++;
}


void FamilyTree::preorder()
{
    traverse(root, 0);
}


void FamilyTree::postorder()
{
    traverse(root, 1);
}


void FamilyTree::traverse(Person* person, int order)
{
    if (person == nullptr)
    {
        return;
    }

    if (order == 1) 
    {
        for(int i = 0; i < person->child_count; i++)
        {
            traverse(person->children[i], order);
        }
    }

    std::cout << " Name: " << person->name << "  Child count: " << person->child_count << "\n";

    if (order == 0) 
    {
        for(int i = 0; i < person->child_count; i++)
        {
            traverse(person->children[i], order);
        }
    }
}