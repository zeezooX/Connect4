#include <windows.h>
#include <conio.h>
#include "ai.h"
#include "game.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));

    setup();

    string str[] =
    {
        "    ____   ___   _   _  _   _  _____   ____  _____   _  _   \n",
        "   / ___| / _ \\ | \\ | || \\ | || ____| / ___||_   _| | || |  \n",
        "  | |    | | | ||  \\| ||  \\| ||  _|  | |      | |   | || |_ \n",
        "  | |___ | |_| || |\\  || |\\  || |___ | |___   | |   |__   _|\n",
        "   \\____| \\___/ |_| \\_||_| \\_||_____| \\____|  |_|      |_|  \n"
    };
    cout << endl;
    for (string s : str)
    {
        setColor(0, 0, 1, 0);
        cout << s.substr(0, 9);
        setColor(1, 1, 0, 0);
        cout << s.substr(9, 7);
        setColor(0, 0, 1, 0);
        cout << s.substr(16, 36);
        setColor(1, 0, 0, 0);
        cout << s.substr(51);
    }
    cout << endl
         << endl;
    ;
    setColor(1, 1, 1, 0);

    while (1)
    {
        setCursor(0, 8);
        cout << "                                                                ";
        setCursor(0, 8);
        cout << " Select difficulty (1-9), or enter (0) for player-vs-player: ";
        int x = getch() - 48;
        cout << x;
        displayTable();
        Beep(349, 100);
        long long bitboard[2] = {0, 0};
        int height[7] = {0, 7, 14, 21, 28, 35, 42};
        int counter = 0;
        int moves[42];
        setCursor(16, 26);
        printf("                     ");
        if (!x)
        {
            while (1)
            {
                setCursor(16, 26);

                setColor(1, (counter & 1), 0, 0);
                cout << "Player ";
                cout << ((counter&1) + 1);
                setColor(1, 1, 1, 0);
                cout << "'s turn: ";

                int y = getch() - 48;
                y--;
                makeMove(y, height, bitboard, &counter, moves);
                setCursor(16, 26);
                printf("                     ");
                setCursor(16, 26);

                if (isWin(bitboard[(counter - 1) & 1]))
                {
                    setColor(1, ((counter - 1) & 1), 0, 0);
                    cout << "PLAYER ";
                    cout << (((counter - 1) & 1) + 1);
                    setColor(1, 1, 1, 0);
                    cout << " WON!";
                    Beep(1046, 250);
                    Beep(698, 250);
                    Beep(1046, 250);
                    break;
                }
                else if (listMoves(height).empty())
                {
                    cout << "DRAW!";
                    Beep(698, 250);
                    Beep(1046, 250);
                    Beep(698, 250);
                    break;
                }
                else Beep(523, 100);
            }
        }
        else if (x < 10 && x > 0)
        {
            while (1)
            {
                if (counter & 1)
                {
                    setCursor(16, 26);

                    setColor(1, 1, 0, 0);
                    cout << "Computer";
                    setColor(1, 1, 1, 0);
                    cout << "'s turn...";

                    int y = minimax(bitboard, height, INT_MIN, INT_MAX, x, 1).first;
                    makeMove(y, height, bitboard, &counter, moves);
                    setCursor(16, 26);
                    printf("                     ");
                    setCursor(16, 26);
                    if (isWin(bitboard[1]))
                    {
                        setColor(1, 1, 0, 0);
                        cout << "COMPUTER";
                        setColor(1, 1, 1, 0);
                        cout << " WON!";
                        Beep(1046, 250);
                        Beep(698, 250);
                        Beep(1046, 250);
                        break;
                    }
                    else if (listMoves(height).empty())
                    {
                        cout << "DRAW!";
                        Beep(698, 250);
                        Beep(1046, 250);
                        Beep(698, 250);
                        break;
                    }
                    else Beep(523, 100);
                }
                else
                {
                    setCursor(16, 26);

                    setColor(1, 0, 0, 0);
                    cout << "Your";
                    setColor(1, 1, 1, 0);
                    cout << " turn: ";

                    int y = getch() - 48;
                    y--;
                    makeMove(y, height, bitboard, &counter, moves);
                    setCursor(16, 26);
                    printf("                     ");
                    setCursor(16, 26);
                    if (isWin(bitboard[0]))
                    {
                        setColor(1, 0, 0, 0);
                        cout << "YOU";
                        setColor(1, 1, 1, 0);
                        cout << " WON!";
                        Beep(1046, 250);
                        Beep(698, 250);
                        Beep(1046, 250);
                        break;
                    }
                    else if (listMoves(height).empty())
                    {
                        cout << "DRAW!";
                        Beep(698, 250);
                        Beep(1046, 250);
                        Beep(698, 250);
                        break;
                    }
                    else Beep(523, 100);
                }
            }
        }
    }
}
