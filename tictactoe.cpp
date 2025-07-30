#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void showBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

bool checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    
   
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    
    return false;
}

int main() {
    cout << "=== TIC TAC TOE - TWO PLAYERS ===\n";
    cout << "Player 1 is X, Player 2 is O\n";
    cout << "Enter position numbers 1-9 to make your move\n";
    
    showBoard();
    
    for (int turn = 0; turn < 9; turn++) {
        int choice;
        
        if (turn % 2 == 0) {
            cout << "Player 1 (X), enter position (1-9): ";
        } else {
            cout << "Player 2 (O), enter position (1-9): ";
        }
        
        cin >> choice;
        
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        
        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            if (turn % 2 == 0) {
                board[row][col] = 'X';
            } else {
                board[row][col] = 'O';
            }
        } else {
            cout << "Invalid move! Try again.\n";
            turn--; 
            continue;
        }
        
        showBoard();
        
        if (checkWin()) {
            if (turn % 2 == 0) {
                cout << "Player 1 (X) Wins!\n";
            } else {
                cout << "Player 2 (O) Wins!\n";
            }
            return 0;
        }
    }
    
    cout << "It's a Draw!\n";
    return 0;
}