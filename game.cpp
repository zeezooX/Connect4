#include <windows.h>
#include "game.h"
#include <bits/stdc++.h>

using namespace std;

HANDLE hConsole;

void displayTable()
{
    setCursor(0, 9);
    setColor(0, 0, 1, 0);
    cout << "\n                +---+---+---+---+---+---+---+\n                |   |   |   |   |   |   |   |\n                +---+---+---+---+---+---+---+\n                |   |   |   |   |   |   |   |\n                +---+---+---+---+---+---+---+\n                |   |   |   |   |   |   |   |\n                +---+---+---+---+---+---+---+\n                |   |   |   |   |   |   |   |\n                +---+---+---+---+---+---+---+\n                |   |   |   |   |   |   |   |\n                +---+---+---+---+---+---+---+\n                |   |   |   |   |   |   |   |\n                +---+---+---+---+---+---+---+\n            ";
    setColor(1, 1, 1, 0);
    cout << "\n                 (1) (2) (3) (4) (5) (6) (7)\n\n";
}

void setColor(bool red, bool green, bool blue, bool highlight)
{
    SetConsoleTextAttribute(hConsole,
                            (red ? FOREGROUND_RED : 0) |
                            (green ? FOREGROUND_GREEN : 0) |
                            (blue ? FOREGROUND_BLUE : 0) |
                            (highlight ? (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) : 0)
                           );
}

void setCursor(int col, int line)
{
    COORD coord;
    coord.X = col;
    coord.Y = line;
    SetConsoleCursorPosition(hConsole, coord);
}

void setup()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    static CONSOLE_FONT_INFOEX fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, 0, &fontex);
    fontex.FontWeight = 700;
    fontex.dwFontSize.X = 24;
    fontex.dwFontSize.Y = 24;
    SetCurrentConsoleFontEx(hConsole, NULL, &fontex);

    SetConsoleTitleA("Connect Four");

    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, 800, 800, TRUE);
}

void makeMove(int col, int height[], long long bitboard[], int *counter, int moves[])
{
    vector<int> v = listMoves(height);
    if(!count(v.begin(), v.end(), col)) return;

    long long m = 1LL << height[col]++;
    bitboard[(*counter) & 1] ^= m;
    moves[(*counter)++] = col;

    for(int a = 0; a < 2; a++)
    {
        setColor(1, a, 0, 0);
        for(int i = 18, k = 0; i <= 42; i += 4, k++)
        {
            for(int j = 21; j >= 11; j -= 2, k++)
            {
                if(bitboard[a] & (1LL << k))
                {
                    if(height[col] == k + 1)
                    {
                        setColor(1, a, 0, 1);
                        setCursor(i - 1, j);
                        cout << " O ";
                        setColor(1, a, 0, 0);
                    }
                    else
                    {
                        setCursor(i - 1, j);
                        cout << " O ";
                    }
                }
            }
        }
    }

    setColor(1, 1, 1, 0);
}

vector<int> listMoves(int height[])
{
    vector<int> moves;
    long long TOP = 283691315109952LL;
    for(int col = 0; col <= 6; col++)
    {
        if ((TOP & (1LL << height[col])) == 0) moves.push_back(col);
    }
    return moves;
}

bool isWin(long long bitboard)
{
    int directions[4] = {1, 7, 6, 8};
    long long bb;
    for(int direction : directions)
    {
        bb = bitboard & (bitboard >> direction);
        if ((bb & (bb >> (2 * direction))) != 0) return true;
    }
    return false;
}
