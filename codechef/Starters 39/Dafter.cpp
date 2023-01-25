#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
 
vector<int> subtrees;
vector<vector<pair<int, int>>> edges;
 
int dfs(int node, int parent, bool blocked)
{
  int nodes = 1;
  for (auto it : edges[node])
  {
    if (it.first == parent)
      continue;
    int x = dfs(it.first, node, (blocked || it.second));
    nodes += x;
    if (it.second && !blocked)
      subtrees.push_back(x);
  }
  return nodes;
}
 
void mainSolve()
{
  int n, k;
  cin >> n >> k;
  edges.clear();
  edges.resize(n + 1);
  for (int i = 1; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
  subtrees.clear();
  dfs(1, 0, false);
  sort(subtrees.begin(), subtrees.end());
  reverse(subtrees.begin(), subtrees.end());
  int infected = n;
  if (infected <= k)
  {
    cout << 0 << endl;
    return;
  }
  for (int i = 0; i < subtrees.size(); i++)
  {
    infected -= subtrees[i];
    if (infected <= k)
    {
      cout << (i + 1) << endl;
      return;
    }
  }
  cout << -1 << endl;
}
 
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--)
  {
    mainSolve();
  }
  return 0;
}