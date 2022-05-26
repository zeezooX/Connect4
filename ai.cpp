#include "ai.h"
#include "game.h"
#include <bits/stdc++.h>

using namespace std;

pair<int, int> minimax(long long bitboard[], int height[], int alpha, int beta, int depth, bool isMax)
{
    vector<int> moves = listMoves(height);
    return make_pair(moves[rand() % moves.size()], 0);
}

int scoreBoard(long long bitboard[])
{

}
