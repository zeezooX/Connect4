#include <windows.h>
#include "ai.h"
#include "game.h"
#include "main.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    setup();

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

    while(1)
    {
        setCursor(0, 2);
        printf("                                                               ");
        setCursor(0, 2);
        printf("Select difficulty (1-9), or enter (0) for player-vs-player: ");
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
                printf("Player %i's turn: ", (counter & 1) + 1);
                int y;
                scanf("%i", &y);
                y--;
                makeMove(y, height, bitboard, &counter, moves);
                setCursor(0, 20);
                printf("                     ");
                setCursor(0, 20);
                if(isWin(bitboard[(counter - 1) & 1]))
                {
                    printf("PLAYER %i WON!", ((counter - 1) & 1) + 1);
                    break;
                }
            }
        }
        else
        {

        }
    }
}
