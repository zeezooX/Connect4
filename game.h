#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

void displayTable();
void setColor(bool red, bool green, bool blue, bool highlight);
void setCursor(int col, int line);
void setup();
void makeMove(int col, int height[], long long bitboard[], int *counter, int moves[]);
vector<int> listMoves(int height[]);
bool isWin(long long bitboard);
