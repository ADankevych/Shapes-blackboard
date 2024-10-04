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


class Figure {
public:
    virtual void draw(Board &board, string input) = 0;

};

class Triangle : public Figure {
public:
    void draw(Board &board, string input) override {
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
                    board.grid[posY][leftMost] = '*';
                }
                if (rightMost >= 0 && rightMost < BOARD_WIDTH && leftMost != rightMost) {
                    board.grid[posY][rightMost] = '*';
                }
            }
        }
        for (int j = 0; j < 2 * height - 1; j++) {
            int baseX = x - height + 1 + j;
            int baseY = y + height - 1;

            if (baseX >= 0 && baseX < BOARD_WIDTH && baseY < BOARD_HEIGHT) {
                board.grid[baseY][baseX] = '*';
            }
        }
    }

};

class Rectangle : public Figure {
public:
    void draw(Board &board, string input) override {
        int pos = input.find(' ');
        int x = stoi(input.substr(0, pos));
        string remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int y = stoi(remaining.substr(0, pos));
        remaining = remaining.substr(pos + 1);
        pos = remaining.find(' ');
        int width = stoi(remaining.substr(0, pos));
        remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int height = stoi(remaining.substr(0, pos));

        if (width <= 0 || height <= 0) {
            cout << "Invalid input" << endl;
            return;
        }

        for(int i = y; i < y + height; i++) {
            for(int j = x; j < x + width; j++) {
                if(i == y || i == y + height - 1 || j == x || j == x + width - 1) {
                    board.grid[i][j] = '*';
                }
            }
        }

    }
};

class Circle : public Figure {
public:
    void draw(Board &board, string input) override {
        int pos = input.find(' ');
        int x = stoi(input.substr(0, pos));
        string remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int y = stoi(remaining.substr(0, pos));
        remaining = remaining.substr(pos + 1);
        pos = remaining.find(' ');
        int radius = stoi(remaining.substr(0, pos));

        if (radius <= 0) {
            cout << "Invalid input" << endl;
            return;
        }

        for(int i = y - radius; i <= y + radius; i++) {
            for(int j = x - radius; j <= x + radius; j++) {
                if((i - y) * (i - y) + (j - x) * (j - x) <= radius * radius &&
                        (i - y) * (i - y) + (j - x) * (j - x) >= (radius-0.5) * (radius-0.5) ) {
                    if(i >= 0 && i < BOARD_HEIGHT && j >= 0 && j < BOARD_WIDTH) {
                        board.grid[i][j] = '*';
                    }
                }
            }
        }
    }

};

class Square : public Figure {
public:
    void draw(Board &board, string input) override {
        int pos = input.find(' ');
        int x = stoi(input.substr(0, pos));
        string remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int y = stoi(remaining.substr(0, pos));
        remaining = remaining.substr(pos + 1);
        int length = stoi(remaining);

        if (length <= 0) {
            cout << "Invalid input" << endl;
            return;
        }

        for(int i = y; i < y + length; i++) { // Maybe in future it will be realized with using Rectangle method draw
            for(int j = x; j < x + length; j++) {
                if(i == y || i == y + length - 1 || j == x || j == x + length - 1) {
                    board.grid[i][j] = '*';
                }
            }
        }
    }

};


int main() {
    Board board;
    //Triangle triangle;
    //triangle.draw(board,"12 4 3");
    //Rectangle rectangle;
    //rectangle.draw(board, "10 4 5 4");
    //Circle circle;
    //circle.draw(board, "25 25 3");
    Square square;
    square.draw(board, "10 4 5");

    board.print();
    return 0;
}