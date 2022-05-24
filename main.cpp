#include <windows.h>
#include "algorithms.h"
#include <bits/stdc++.h>

using namespace std;

HANDLE hConsole;
void setColor(bool red, bool green, bool blue, bool highlight);
void setCursor(int column, int line);

int main()
{
    //make text bold and bigger
    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hConsole, 0, &fontex);
    fontex.FontWeight = 700;
    fontex.dwFontSize.X = 24;
    fontex.dwFontSize.Y = 24;
    SetCurrentConsoleFontEx(hConsole, NULL, &fontex);

    //welcoming message
    printf("Welcome to ");
    setColor(0, 0, 1, 0);
    printf("C");
    setColor(1, 1, 0, 0);
    printf("O");
    setColor(0, 0, 1, 0);
    printf("NNECT ");
    setColor(1, 0, 0, 0);
    printf("4");
    setColor(1, 1, 1, 0);
    printf("!\n\n");

    //mode select
    printf("Select Mode:\nPlayer vs Player (1)\nPlayer vs Computer (2)\n");
    int x;
    scanf("%i", &x);

}

//change text color
void setColor(bool red, bool green, bool blue, bool highlight)
{
    SetConsoleTextAttribute(hConsole,
                            (red ? FOREGROUND_RED : 0) |
                            (green ? FOREGROUND_GREEN : 0) |
                            (blue ? FOREGROUND_BLUE : 0) |
                            (highlight ? (BACKGROUND_GREEN | BACKGROUND_RED) : 0)
                            );
}

//change position of cursor
void setCursor(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(hConsole, coord);
}
