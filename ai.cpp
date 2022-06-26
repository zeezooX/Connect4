#include "ai.h"
#include "game.h"
#include <bits/stdc++.h>

using namespace std;

pair<int, int> minimax(long long bitboard[], int height[], int alpha, int beta, int depth, bool isMax)
{
    vector<int> moves = listMoves(height);
    if(moves.empty() || depth == 0 || isWin(bitboard[0]) || isWin(bitboard[1]))
        return make_pair(-1, -scoreBoard(bitboard));
    if(isMax)
    {
        int score = INT_MIN;
        int column = moves[rand() % moves.size()];
        for(int col : moves)
        {
            long long c_bitboard[2] = {bitboard[0], bitboard[1]};
            int c_height[7] = {height[0], height[1], height[2], height[3], height[4], height[5], height[6]};

            long long m = 1LL << c_height[col]++;
            c_bitboard[1] ^= m;

            int new_score = minimax(c_bitboard, c_height, alpha, beta, depth-1, 0).second - 1;
            if(new_score > score)
            {
                score = new_score;
                column = col;
            }
            alpha = max(alpha, score);
            if(alpha >= beta)
                break;
        }
        return make_pair(column, score);
    }
    else
    {
        int score = INT_MAX;
        int column = moves[rand() % moves.size()];
        for(int col : moves)
        {
            long long c_bitboard[2] = {bitboard[0], bitboard[1]};
            int c_height[7] = {height[0], height[1], height[2], height[3], height[4], height[5], height[6]};

            long long m = 1LL << c_height[col]++;
            c_bitboard[0] ^= m;

            int new_score = minimax(c_bitboard, c_height, alpha, beta, depth-1, 1).second + 1;
            if(new_score < score)
            {
                score = new_score;
                column = col;
            }
            beta = min(beta, score);
            if(alpha >= beta)
                break;
        }
        return make_pair(column, score);
    }

    //return make_pair(moves[rand() % moves.size()], 0);
}

int scoreBoard(long long bitboard[])
{
    if(isWin(bitboard[0]))
        return 100000;
    if(isWin(bitboard[1]))
        return -100000;

    long long border = -279258638311360LL;
    long long free = ~(bitboard[0] | bitboard[1] | border);
    int score = 0;
    long long directions[] = {1, 7, 6, 8};
    for(int i = 0; i < 2; i++)
    {
        for(int direction : directions)
        {
            long long x = free << direction, y = free >> direction;
            long long a1 = (bitboard[i] & (bitboard[i] >> direction) & (bitboard[i] >> (2LL * direction))) & x;
            long long a2 = (bitboard[i] & (bitboard[i] << direction) & (bitboard[i] << (2LL * direction))) & y;
            long long a = a1 | a2;
            long long b1 = ((bitboard[i] & ~a) & ((bitboard[i] & ~a) >> direction)) & x;
            long long b2 = ((bitboard[i] & ~a) & ((bitboard[i] & ~a) << direction)) & y;
            long long b = b1 | b2;

            score += (10 * __builtin_popcountll(a) + __builtin_popcountll(b)) * (i ? -1 : 1);
        }
    }
    return score;
}
