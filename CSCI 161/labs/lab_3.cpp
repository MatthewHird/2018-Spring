#include <iostream>
using namespace std;


class Flag {
private:
    int width;
    int height;
    char symbol;
    
public:
    Flag(int width, int height, char symbol);
    Flag();
    ~Flag();
    
    int getWidth();
    int getHeight();
    char getSymbol();
    
    void resize(int newWidth, int newHeight);
    void changeSymbol(char newSymbol);
    
    int calculate();    // calculate the number of characters needed to draw this flag
    void draw();
    
    bool bigFlag();     // return true if this Flag object uses more than 25 characters 
                        // to draw; otherwise, return false
};

Flag::Flag(int in_width, int in_height, char in_symbol){
   width = in_width; 
   height = in_height;
   symbol = in_symbol;
}

Flag::Flag(){
    width = 0;
    height = 0;
    symbol = 'X';
}

Flag::~Flag(){

}

int Flag::getWidth(){
    return width;
}

int Flag::getHeight(){
    return height;
}

char Flag::getSymbol(){
    return symbol;
}

void Flag::resize(int newWidth, int newHeight){
    width = newWidth;
    height = newHeight;
    return;
}

void Flag::changeSymbol(char newSymbol){
    cin.get();
    return;
}

int Flag::calculate(){
    return width * height;
}

void Flag::draw(){
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << symbol;
        }
        cout << endl;
    }
}

bool Flag::bigFlag(){
    if(width * height > 25) {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
    Flag starFlag(5, 3, '*');
    Flag *flagPtr = new Flag();

    cout << "info of star flag:\n"
         << "width: " << starFlag.getWidth() << " "
         << "height: " << starFlag.getHeight() << endl;

    starFlag.draw();

    if (starFlag.bigFlag()) {
        cout << "star flag is a big flag.\n";
    } else {
        cout << "star flag is a small flag.\n";
    }
    
    flagPtr->resize(7, 5);
    
    cout << "info of a dynamically created flag:\n"
         << "width: " << flagPtr->getWidth() << " "
         << "height: " << flagPtr->getHeight() << endl;

    flagPtr->draw();

    if (flagPtr->bigFlag()) {
        cout << "the dynamically created flag is a big flag.\n";
    } else {
        cout << "the dynamically created flag is a small flag.\n";
    }

    delete flagPtr;

    return 0;
}
