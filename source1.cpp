#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int SIZE = 3;

void initBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char &player);
bool checkWin(char board[SIZE][SIZE]);
bool isDraw(char board[SIZE][SIZE]);

int main()
{
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    cout << "Welcome to tic-tac-toe game!" << endl;
    cout << "For playing instructions, please read the readme file first!" << endl;
    initBoard(board);
    displayBoard(board);
    
    while (true)
    {
        playerMove(board, currentPlayer);
        displayBoard(board);
        if (checkWin(board))
        {
            cout << "Player " << currentPlayer << " is the winner!" << endl;
            return 0;
        }
        else if (isDraw(board))
        {
            cout << "This match is a draw! Well played guys!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O': 'X';
    }
    return 0;
}

void initBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '.';        
        }
    }
}

void displayBoard(char board[SIZE][SIZE])
{
    cout << "   | 0 | 1 | 2 |" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "---+---+---+---+" << endl;
        cout << " "<< i;
        for (int j = 0; j < SIZE; j++)
        {
            cout << " | " << board[i][j];
        }
        cout << " |" << endl;
    }
    cout << "---+---+---+---+" << endl;
}

void playerMove(char board[SIZE][SIZE], char &player)
{
    cout << "* Player " << player << "'s turn!" << endl;
    int row, column;

    while (1)
    {
        cout << " Row: ";
        cin >> row;
        cout << " Column: ";
        cin >> column;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter again!" << endl;
            continue;
        }
        
        if (row >= 0 && row < 3 && column >= 0 && column < 3 && board[row][column] == '.')
        {
            board[row][column] = player;
            break;
        }
        cout << "Position already taken or invalid range, please enter again!" << endl;
    }
}

bool checkWin(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }

        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }
    
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if (board[2][0] != '.' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        return true;
    }
    return false;
}

bool isDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}