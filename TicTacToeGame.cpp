#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid(3, vector<char>(3, ' '));

void initializegrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void printgrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << std::flush;
}

bool checkwin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            cout << "Player " << grid[i][0] << " won the match" << endl;
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            cout << "Player " << grid[0][i] << " won the match" << endl;
            return true;
        }
    }

    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        cout << "Player " << grid[0][0] << " won the match" << endl;
        return true;
    } else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        cout << "Player " << grid[0][2] << " won the match" << endl;
        return true;
    }

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playerA() {
    int temp;
    cout << "Enter the position for Player A (1-9): ";
    cin >> temp;

    if (temp < 1 || temp > 9) {
        cout << "Wrong input detected. Kindly enter a number between 1 to 9." << endl;
        return;
    }

    int i = (temp - 1) / 3;
    int j = (temp - 1) % 3;

    if (grid[i][j] == ' ') {
        grid[i][j] = 'A';
    } else {
        cout << "Position already occupied. Choose another position." << endl;
    }
}

void playerB() {
    int temp;
    cout << "Enter the position for Player B (1-9): ";
    cin >> temp;

    if (temp < 1 || temp > 9) {
        cout << "Wrong input detected. Kindly enter a number between 1 to 9." << endl;
        return;
    }

    int i = (temp - 1) / 3;
    int j = (temp - 1) % 3;

    if (grid[i][j] == ' ') {
        grid[i][j] = 'B';
    } else {
        cout << "Position already occupied. Choose another position." << endl;
    }
}

int main() {
    initializegrid();
    printgrid();
    while (true) {
        if (checkDraw() || checkwin()) break;
        playerA();
        printgrid();
        if (checkwin() || checkDraw()) break;
        playerB();
        printgrid();
        if (checkDraw() || checkwin()) break;
    }
    if (!checkwin()) {
        cout << "The game is a draw." << endl;
    }
    cout << endl << "Thanks for playing the game coded by Aditya Mishra";
    return 0;
}
