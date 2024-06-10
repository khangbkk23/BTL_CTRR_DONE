#ifndef TSM_H
#define TSM_H

#include <bits/stdc++.h>
#include "bellman.h"
using namespace std;

int resLength(int (*G)[20],int n,const string str);
pair<int,vector<int>> dynamicProgramming(int (*G)[20], int n, char start_vertex, string resStr[20], int resLen[20], vector<vector<pair<int,vector<int>>>> &dp, int visited,int visited_already);
string Traveling(int (*G)[20], int n, char start_vertex);

#endif // TSM_H
