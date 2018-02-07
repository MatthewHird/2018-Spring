#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
    istringstream iss ("15 egg 62");
    
    int x;
    iss >> x;
    cout << x <<endl;
    
    iss >> x;
    cout << x <<endl;
    
    iss >> x;
    cout << x <<endl;
    
    cin >> x;
    
    return 0;
}
