#include "tsm.h"
#include "bellman.h"

int resLength(int (*G)[20], int n, const string str) {
  if (n == 1) return 0;
  int totalDistance = 0;
  for (int i = 2; i < str.length(); ++i) {
    if (str[i] != ' ') {
      int start = str[i - 2] - 'A';
      int end = str[i] - 'A';
      totalDistance += G[start][end];
    }
  }
  return totalDistance;
}

vector<vector<pair<int, vector<int>>>> dp;

pair<int, vector<int>> dynamicProgramming(int (*G)[20], int n, int j,
                                          char start_vertex, int visited) {
  int start = start_vertex - 'A';
  if (visited == ((1 << n) - 1)) {
    if (!G[j][start]) {
      return {INT_MAX, {}};
    }
    return {G[j][start], {j, start}};
  }

  // Check the memoization array
  if (dp[j][visited].first != -1) 
    return dp[j][visited];

  // Implement the retrieval formula
  pair<int, vector<int>> minPath = {INT_MAX, {}};
  for (int i = 0; i < n; ++i) {
    if ((visited >> i) & 1) 
      continue;
    if (!G[j][i]) 
      continue;
    pair<int, vector<int>> newPath = dynamicProgramming(G, n, i, start_vertex, visited | (1 << i));
    if (newPath.first != INT_MAX) {
      int newValue = G[j][i] + newPath.first;
      if (newValue < minPath.first) {
        minPath.first = newValue;
        minPath.second = {j};
        minPath.second.insert(minPath.second.end(), newPath.second.begin(),
                              newPath.second.end());
      }
    }
  }
  dp[j][visited] = minPath;
  return dp[j][visited];
}

string Traveling(int (*G)[20], int n, char start_vertex) {
  int start = start_vertex - 'A';
  string resStr = "";
  dp = vector<vector<pair<int, vector<int>>>>(
      n, vector<pair<int, vector<int>>>(1 << n, {-1, {}}));
  auto minPath = dynamicProgramming(G, n, start, start_vertex, 1 << start);
  auto resPath = minPath.second;

  // Check the Hamilton circuit
  if (minPath.first == INT_MAX || resPath.size() != n + 1) {
    return "-1";
  }

  for (int i = 0; i < resPath.size(); i++) {
    char c = resPath[i] + 'A';
    resStr = resStr + c + " ";
  }
  return resStr;
}
//*======================================================================*//