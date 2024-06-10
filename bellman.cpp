#include "bellman.h"

void setPreVal(int n, int* Value, int* Previous) {
  for (int i = 0; i < n; i++) {
    Value[i] = -1;
    Previous[i] = -1;
  }
}

void BF(int (*G)[20], int n, char start_vertex, int Value[], int Previous[]) {
  int u = start_vertex - 'A';
  if (Value[u] == -1) {
    Value[u] = 0;
  }

  int* newValue = new int[n];
  int* newPrevious = new int[n];
  for (int i = 0; i < n; i++) {
    newValue[i] = Value[i];
    newPrevious[i] = Previous[i];
  }
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      if (G[u][v] == 0 || Value[u] == -1) continue;
      if (Value[u] + G[u][v] < Value[v] || Value[v] == -1) {
        if ((Value[u] + G[u][v] < newValue[v]) || newValue[v] == -1) {
          newValue[v] = Value[u] + G[u][v];
          newPrevious[v] = u;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    Value[i] = newValue[i];
    Previous[i] = newPrevious[i];
  }
  delete[] newValue;
  delete[] newPrevious;
}

string Path(int* Previous, int end_vertex) {
  string path = "";
  path += (end_vertex + 'A');

  if (Previous[end_vertex] == -1) return path;

  return Path(Previous, Previous[end_vertex]) + " " + path;
}

string BF_Path(int (*G)[20], int n, char start_vertex, char end_vertex) {
  int* Value = new int[n];
  int* Previous = new int[n];
  setPreVal(n, Value, Previous);

  int end = end_vertex - 'A';

  for (int i = 0; i < n - 1; ++i) {
    BF(G, n, start_vertex, Value, Previous);
  }
  delete[] Value;
  return Path(Previous, end);
}