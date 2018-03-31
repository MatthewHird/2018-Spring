#include "person.h"
#include "queue.h"
#include <iostream>

int main()
{
    Queue<Person> per_que;  

    Person bob("Bob");
    Person noname;

    per_que.enqueue(bob);
    std::cout << per_que.get_size() << "\n";
    per_que.enqueue(noname);
    std::cout << per_que.get_size() << "\n";
    Person newman = per_que.dequeue();
    newman.display();
    std::cout << (per_que.dequeue()).get_name() << "\n";

    std::cout << per_que.get_size() << "\n";  

    return 0;
}