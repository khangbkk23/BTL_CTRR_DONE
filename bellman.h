#ifndef BELLMAN_H
#define BELLMAN_H

#include <bits/stdc++.h>
using namespace std;

void setPreVal(int n, int* Value, int* Previous);
void BF(int (*G)[20], int n,char start_vertex, int *Value, int *Previous);
string Path(int * Previous, int end_vertex);
string BF_Path(int (*G)[20], int n, char start_vertex, char end_vartex);

#endif // BELLMAN_H
