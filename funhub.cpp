
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 1. TIC-TAC-TOE CLASS
class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() { resetBoard(); currentPlayer = 'X'; }

    void resetBoard() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = '1' + (i * 3 + j);
    }

    void displayBoard() {
        cout << "\nTic-Tac-Toe Board:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
    }

    bool makeMove(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++)
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                return true;
        return (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
               (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        return true;
    }

    void switchPlayer() { currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; }

    void playGame() {
        int move;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
            if (!makeMove(move)) continue;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

// 2. NUMBER GUESSING GAME
class NumberGuessingGame {
public:
    void startGame() {
        srand(time(0));
        int secretNumber = rand() % 100 + 1, attempts = 0, guess;

        cout << "Guess a number between 1 and 100:\n";
        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            if (guess > secretNumber) cout << "Too high! Try again.\n";
            else if (guess < secretNumber) cout << "Too low! Try again.\n";
            else cout << "Congratulations! You guessed it in " << attempts << " attempts!\n";
        } while (guess != secretNumber);
    }
};

// 3. MATH PUZZLE GAME
class MathPuzzle {
public:
    void startGame() {
        srand(time(0));
        char choice;
        int score = 0;

        cout << "Solve math problems to earn points!\n";
        while (true) {
            int num1 = rand() % 20 + 1, num2 = rand() % 20 + 1, correctAnswer, userAnswer;
            char operation;
            int op = rand() % 3;

            switch (op) {
                case 0: operation = '+'; correctAnswer = num1 + num2; break;
                case 1: operation = '-'; correctAnswer = num1 - num2; break;
                case 2: operation = '*'; correctAnswer = num1 * num2; break;
            }

            cout << num1 << " " << operation << " " << num2 << " = ";
            cin >> userAnswer;

            if (userAnswer == correctAnswer) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Wrong! The correct answer was " << correctAnswer << ".\n";
                break;
            }

            cout << "Your score: " << score << "\nContinue? (y/n): ";
            cin >> choice;
            if (choice == 'n' || choice == 'N') break;
        }
    }
};



// MAIN GAME HUB
int main() {
    int choice;
    while (true) {
        cout<<"\n==============|| WELCOME TO FUN HUB !||============\n";
        cout<<"Please choose a game which you want to play";
        cout << "\n=== FUN HUB ===\n";
        cout << "1. Tic-Tac-Toe\n2. Number Guessing\n3. Math Puzzle\n4. Exit\n";
        cout << "Select a game: ";
        cin >> choice;

        if (choice == 5) break;
        if (choice == 1) { TicTacToe game; game.playGame(); }
        else if (choice == 2) { NumberGuessingGame game; game.startGame(); }
        else if (choice == 3) { MathPuzzle game; game.startGame(); }
        
        else cout << "Invalid choice! Try again.\n";
    }

    cout << "Thanks for playing Fun Hub!\n";
    return 0;
}

