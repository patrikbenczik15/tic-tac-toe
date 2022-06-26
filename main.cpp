#include <iostream>
using namespace std;

bool game_on = true;
char board[10] = {
    'n',
    '#',
    '#',
    '#',
    '#',
    '#',
    '#',
    '#',
    '#',
    '#',
};

void displayBoard() {
    // ! External board borders
    // for (int i = 1; i <= 9; i++) {
    //     cout << '|' << board[i] << '|';
    //     if (i % 3 == 0)
    //         cout << endl;
    // }

    cout << board[1] << '|' << board[2] << "|" << board[3] << '\n';
    cout << board[4] << '|' << board[5] << "|" << board[6] << '\n';
    cout << board[7] << '|' << board[8] << "|" << board[9] << '\n';
}

void clearBoard() {
    for (int i = 1; i < 10; i++)
        board[i] = '#';
}
// ! comment all the * highlighted comments after the code if you wish player 1 to start everytime
int p1_starter = 1; // * initialize variables to switch the starter mark

void askX();
void askO();
bool checkWin();
void askNew();
void askX() {
    while (game_on == true) {
        int input;
        cout << "Player 1, choose input (1-9): ";
        cin >> input;
        if (board[input] == '#') {
            board[input] = 'X';
            displayBoard();
            bool result = checkWin();
            if (result == false)
                askO();
            else {
                cout << "Player 1 wins!\n";
                p1_starter = 0; // * player 1 starts after player 1 wins
                askNew();
            }
        } else {
            cout << "You can't place your mark there!\n";
        }
    }
}

void askO() {
    while (game_on == true) {
        int input;
        cout << "Player 2, choose input (1-9): ";
        cin >> input;
        if (board[input] == '#') {
            board[input] = 'O';
            displayBoard();
            bool result = checkWin();
            if (result == false)
                askX();
            else {
                cout << "Player 2 wins!\n";
                p1_starter = 1; // * player 1 starts after player 2 wins
                askNew();
            }
        } else {
            cout << "You can't place your mark there!\n";
        }
    }
}

void askNew();

bool checkWin() {
    // ! Check horizontally
    if (board[1] == board[2] && board[2] == board[3] && board[1] != '#' ||
        board[4] == board[5] && board[5] == board[6] && board[4] != '#' ||
        board[7] == board[8] && board[8] == board[9] && board[7] != '#' ||
        // ! Check vertically
        board[1] == board[4] && board[4] == board[7] && board[1] != '#' ||
        board[2] == board[5] && board[5] == board[8] && board[2] != '#' ||
        board[3] == board[6] && board[6] == board[9] && board[3] != '#' ||
        // ! Check diagonally
        board[1] == board[5] && board[5] == board[9] && board[1] != '#' ||
        board[3] == board[5] && board[5] == board[7] && board[3] != '#') {
        cout << "Game Over!\n";

        return true;

    } else if (board[1] != '#' &&
               board[2] != '#' &&
               board[3] != '#' &&
               board[4] != '#' &&
               board[5] != '#' &&
               board[6] != '#' &&
               board[7] != '#' &&
               board[8] != '#' &&
               board[9] != '#') {
        cout << "Game Over! Draw!\n";
        askNew();
    }
}

void askNew() {
    game_on = false;
    char answer;
    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
        cout << "Would you want to play again? (Y/N): ";
        cin >> answer;
    }
    if (answer == 'Y' || answer == 'y') {
        game_on = true;
        clearBoard();
        displayBoard();
        if (p1_starter == 1) // * change this whole if-else statement with only askX()
            askX();
        else
            askO();
    } else {
        cout << "Thanks for playing!\n";
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";

    displayBoard();
    askX();

    return 0;
}