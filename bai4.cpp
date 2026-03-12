#include <iostream>

using namespace std;

void printBorder(int cols) {
    for (int i = 0; i < cols; i++) {
        cout << "+ - - - - ";
    }
    cout << "+\n";
}

void printBody(int cols) {
    for (int i = 0; i < cols; i++) {
        cout << "|         ";
    }
    cout << "|\n";
}

void drawGrid(int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        printBorder(cols);
        for (int i = 0; i < 4; i++) {
            printBody(cols);
        }
    }
    printBorder(cols);
}

int main() {
    drawGrid(2, 2); 
    
    cout << "\n------------------\n\n";
    
    drawGrid(4, 4); 
}
