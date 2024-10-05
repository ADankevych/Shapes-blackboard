#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int BOARD_WIDTH = 90;
const int BOARD_HEIGHT = 30;

vector<vector<char>> grid(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' '));

map<int, string> allShapes;
int currentID = 0;

struct Board {
    void print() { // Here I used a part of the code from assignment example
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
    virtual void draw(string input) = 0;

};

class Triangle : public Figure {
public:
    void draw(string input) override {
        allShapes[currentID] = " triangle"+input;
        currentID++;
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
        allShapes[currentID] = " rectangle"+input;
        currentID++;
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
                    grid[i][j] = '*';
                }
            }
        }

    }
};

class Circle : public Figure {
public:
    void draw(string input) override {
        allShapes[currentID] = " circle"+input;
        currentID++;
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
                        grid[i][j] = '*';
                    }
                }
            }
        }
    }

};

class Square : public Figure {
public:
    void draw(string input) override {
        allShapes[currentID] = " square"+input;
        currentID++;
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
                    grid[i][j] = '*';
                }
            }
        }
    }

};

class Line : public Figure {
public:
    void draw(string input) override {
        allShapes[currentID] = " line"+input;
        currentID++;
        int pos = input.find(' ');
        int xStart = stoi(input.substr(0, pos));
        string remaining = input.substr(pos + 1);
        pos = remaining.find(' ');
        int yStart = stoi(remaining.substr(0, pos));
        remaining = remaining.substr(pos + 1);
        pos = remaining.find(' ');
        int xEnd = stoi(remaining.substr(0, pos));
        int yEnd = stoi(remaining.substr(pos + 1));

        for (int i = 0; i < max(abs(xEnd - xStart), abs(yEnd - yStart)); i++) {
            int x = xStart + ((xEnd - xStart) * i) / max(abs(xEnd - xStart), abs(yEnd - yStart));
            int y = yStart + ((yEnd - yStart) * i) / max(abs(xEnd - xStart), abs(yEnd - yStart));
            if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT) {
                grid[y][x] = '*';
            }
        }
    }

};

int main() {
    Board board;
    // Triangle triangle;
    // triangle.draw("12 4 3");
    // Rectangle rectangle;
    // rectangle.draw("10 4 5 4");
    // Circle circle;
    // circle.draw("25 25 3");
    // Square square;
    // square.draw("10 4 5");
    // Line line;
    // line.draw("25 10 28 15");

    cout << "Hello, welcome to shapes blackboard! \n"
         << "Enter one of the commands: \n"
         << "draw - Draw blackboard to the console \n"
         << "list - Print all added shapes with their IDs and parameters \n"
         << "shapes - Print a list of all available shapes and parameters for add call \n"
         << "add - Add shape to the blackboard \n"
         << "undo - Remove the last added shape from the blackboard\n"
         << "clear - Remove all shapes from blackboard\n"
         << "save - Save the blackboard to the file\n"
         << "load - Load a blackboard from the file\n"
         << "exit - Exit the program\n";

    string input;
    while (true) {
        getline(cin, input);
        if (input == "draw") {
            board.print();
        } else if (input == "shapes") {
            cout << "triangle - coordinates of the top(upper) point and height of the triangle\n"
                 << "rectangle - coordinates of the upper left point and width height\n"
                 << "circle - coordinates of the center and radius\n"
                 << "square - coordinates of the upper left point and side length\n"
                 << "line - coordinates of start and end points\n";
        } else if (input == "clear") {
            board = Board();
        } else if (input == "list") {
            for (auto &shape: allShapes) {
                cout << shape.first << shape.second << endl;
            }
        } else if (input == "exit") {
            break;
        }

        cout << endl;
    }

    // board.print();
    return 0;
}