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
    virtual void draw(string input) = 0;

};

class Triangle : public Figure {
public:
    void draw(string input) override {
        int pos = input.find(' ');
        int x = stoi(input.substr(0, pos));
        string remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int y = stoi(remaining.substr(pos + 1));
        remaining = remaining.substr(pos + 1);
        pos = remaining.find(' ');
        int height = stoi(remaining.substr(0, pos));

        if (height <= 0) {
            cout << "Invalid input" << endl;
            return;
        }

        for (int i = 0; i < height; i++) {  // Here I used a part of the code from assignment example
            int leftMost = x - i;
            int rightMost = x + i;
            int posY = y + i;

            if (posY < BOARD_HEIGHT) {
                if (leftMost >= 0 && leftMost < BOARD_WIDTH) {
                    grid[posY][leftMost] = '*';
                }
                if (rightMost >= 0 && rightMost < BOARD_WIDTH && leftMost != rightMost) {
                    grid[posY][rightMost] = '*';
                }
            }
        }
        for (int j = 0; j < 2 * height - 1; j++) {
            int baseX = x - height + 1 + j;
            int baseY = y + height - 1;

            if (baseX >= 0 && baseX < BOARD_WIDTH && baseY < BOARD_HEIGHT) {
                grid[baseY][baseX] = '*';
            }
        }
    }

};

class Rectangle : public Figure {
public:
    void draw(string input) override {
        int pos = input.find(' ');
        int x = stoi(input.substr(0, pos));
        string remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int y = stoi(remaining.substr(pos + 1));
        remaining = remaining.substr(pos + 1);
        pos = remaining.find(' ');
        int width = stoi(remaining.substr(0, pos));
        remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int height = stoi(remaining.substr(pos + 1));

        if (width <= 0 || height <= 0) {
            cout << "Invalid input" << endl;
            return;
        }

        for(int i = y; i < y + height; i++) {
            for(int j = x; j < x + width; j++) {
                if(i == y || i == y + height - 1 || j == x || j == x + width - 1) {
                    grid[i][j] = '*';
                }
            }
        }


    }
};

class Circle : public Figure {

};

class Square : public Figure {

};


int main() {
    Board board;
    Triangle triangle;
    triangle.draw("12 2 2");
    Rectangle rectangle;
    rectangle.draw("10 5 4 4");
    rectangle.print();

    return 0;
}