#include <windows.h>
#include "ai.h"
#include "game.h"
#include "main.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    setup();

//    printf("Welcome to ");
//    setColor(0, 0, 1, 0);
//    printf("C");
//    setColor(1, 1, 0, 0);
//    printf("O");
//    setColor(0, 0, 1, 0);
//    printf("NNECT ");
//    setColor(1, 0, 0, 0);
//    printf("4");
//    setColor(1, 1, 1, 0);
//    printf("!\n\n");

    string str[] =
    {
        "\n",
        "   ____   ___   _   _  _   _  _____   ____  _____   _  _   \n",
        "  / ___| / _ \\ | \\ | || \\ | || ____| / ___||_   _| | || |  \n",
        " | |    | | | ||  \\| ||  \\| ||  _|  | |      | |   | || |_ \n",
        " | |___ | |_| || |\\  || |\\  || |___ | |___   | |   |__   _|\n",
        "  \\____| \\___/ |_| \\_||_| \\_||_____| \\____|  |_|      |_|  \n",
        "\n",
        "\n"
    };

    for(string s : str)
        cout << s;

    while(1)
    {
        setCursor(0, 8);
        printf("                                                               ");
        setCursor(0, 8);
        printf(" Select difficulty (1-9), or enter (0) for player-vs-player: ");
        int x;
        scanf("%i", &x);
        displayTable();
        long long bitboard[2] = {0, 0};
        int height[7] = {0, 7, 14, 21, 28, 35, 42};
        int counter = 0;
        int moves[42];
        if(!x)
        {
            while(1)
            {
                setCursor(16, 26);

                setColor(1, ((counter)& 1), 0, 0);
                cout << "Player ";
                cout << (((counter)& 1) + 1);
                setColor(1, 1, 1, 0);
                cout << "'s turn: ";

                int y;
                scanf("%i", &y);
                y--;
                makeMove(y, height, bitboard, &counter, moves);
                setCursor(16, 26);
                printf("                     ");
                setCursor(16, 26);
                if(isWin(bitboard[(counter - 1) & 1]))
                {
                    setColor(1, ((counter - 1)& 1), 0, 0);
                    cout << "PLAYER ";
                    cout << (((counter - 1)& 1) + 1);
                    setColor(1, 1, 1, 0);
                    cout << " WON!";
                    break;
                }
            }
        }
        else
        {

        }
    }
}
