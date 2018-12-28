#include <iostream>


int main()
{
    int start_val;
    int max_loops;
    int adder;
    int answer = 0;

    std::cout << "Please input starting integer value\n"
              << ">>> ";

    std::cin >> start_val;
    std::cin.ignore();

    std::cout << "Please input number of iterations\n"
              << ">>> ";

    std::cin >> max_loops;
    std::cin.ignore();

    adder = start_val;

    for (int i = 0; i <= max_loops; i++)
    {
        answer += adder;
        adder++;
    }

    std::cout << "Final value: " << answer << "\n";
    return 0;
}