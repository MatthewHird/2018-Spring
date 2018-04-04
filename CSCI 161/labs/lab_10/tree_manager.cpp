#include "tree_manager.h"
#include "family_tree.h"
#include "person.h"
#include "stack.h"
#include <iostream>
#include <fstream>


TreeManager::TreeManager()
{

}


TreeManager::~TreeManager()
{}


void TreeManager::run()
{
    fin.open(save_file);
    if (fin.fail())
    {
        return;
    }

    load();

    fin.close();

    std::cout << "Tree preorder: \n\n";
    tree.preorder();
    std::cout << "\n\nTree postorder: \n\n";
    tree.postorder();
}


void TreeManager::load()
{
    std::string root_name;
    std::string line;
    
    Person* end = new Person;
    end->child_count = -1;
    stack.push(end);
    
    Person* parent = new Person;
    tree.insert_root(parent);
    Person* child;

    getline(fin, root_name);
    parent->name = root_name;
    
    if (!getline(fin, line))
    {
        return;
    }

    while (parent->child_count != -1)
    {
        getline(fin, line);

        if (line == "<")
        {
            stack.push(parent);
            parent = child;
        }
        else if (line == ">")
        {
            child = parent;
            parent = stack.pop();
        }
        else
        {
            child = new Person;
            child->name = line;
            tree.insert(parent, child);
        }
    }

    delete end;
}
