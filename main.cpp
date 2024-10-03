#include <iostream>
#include <vector>
using namespace std;

const int BOARD_WIDTH = 90;
const int BOARD_HEIGHT = 30;

struct Board {  // Here I used a part of the code from assignment example
    vector<vector<char>> grid;

    Board() : grid(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' ')) {}

    void print() {
        for (int i = 0; i < BOARD_WIDTH / 2; i++) {
            cout << " -";
        }
        cout << "\n";
        for (auto &row: grid) {
            cout << "|";
            for (char c: row) {
                cout << c;
            }
            cout << "|\n";
        }
        for (int i = 0; i < BOARD_WIDTH / 2; i++) {
            cout << " -";
        }
    }
};


class Figure : public Board {
public:
    virtual void draw() = 0;

};

class Triangle : public Figure {


};

class Rectangle : public Figure {

};

class Circle : public Figure {

};

class Square : public Figure {

};


int main() {
    Board board;
    board.print();
    return 0;
}