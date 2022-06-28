#include <bits/stdc++.h>

using namespace std;

pair<int, int> minimax(long long bitboard[], int height[], int alpha, int beta, int depth, bool isMax);
int scoreBoard(long long bitboard[]);

const int M3 = 10;
const int M2 = 1;
const int M1 = 100000;
