#include "tech_dict.h"
#include <iostream>
#include <fstream>


TechDict::TechDict()
{}


TechDict::~TechDict()
{}


void TechDict::run()
{
    load();
    menu();
}


void TechDict::menu()
{
    std::cout << "\n~~~~Welcome to Dave's Dictionary Service~~~~\n\n";

    std::string command;

    do 
    {
        std::cout << "cmd>>> ";
        getline(std::cin, command);

        if (command == "shutdown")
        {
            save();
        }
        else
        {
            std::cout << "\n" << command << dave.search(command) << "\n\n";
        }
    } while (command != "shutdown");
}


void TechDict::load()
{
    int entry_count;
    std::ifstream fin;
    fin.open("TechDictionary.txt");

    if (fin.fail())
    {
        return;
    }

    fin >> entry_count;
    fin.ignore();

    for (int i = 0; i < entry_count; i++)
    {
        std::string key;
        std::string data;

        fin >> key;
        getline(fin, data);

        dave.insert(key, data);
    }

    fin.close();
}


void TechDict::save()
{
    std::ofstream fout;
    fout.open("TechDictionary.txt");

    fout << dave.dump_all();

    fout.close();
}