
#include <bits/stdc++.h>

#ifdef ALGOAT
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*template <class T> using rpq = priority_queue<T, vector<T>, greater<T>>;*/

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1},
          dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

using namespace std;

int n, m;

char A[1000][1000];
int nex[1003][1003];
string dir = "DRUL";
void solve() {

  cin >> n >> m;

  queue<pair<int, int>> q;

  pair<int, int> begin, end;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {

      cin >> A[i][j];

      if (A[i][j] == 'A') {

        begin = {i, j};
      }

      if (A[i][j] == 'M') {

        q.push({i, j});
      }
    }
  }

  q.push(begin);

  nex[begin.F][begin.S] = -1;
  while (!q.empty()) {
    debug(q);

    pair<int, int> u = q.front();

    q.pop();

    if (A[u.F][u.S] == 'A' &&
        (u.F == 0 || u.F == n - 1 || u.S == 0 || u.S == m - 1)) {
      cout << "YES\n";
      string s;
      int d = nex[u.F][u.S];
      while (d != -1) {
        s += dir[d];
        u.F -= dx[d];
        u.S -= dy[d];
        d = nex[u.F][u.S];
      }
      reverse(all(s));
      cout << s.size() << "\n";
      cout << s << "\n";
      debug(s);
      return;
    }
    for (int i = 0; i < 4; i++) {


      pair<int, int> v = {u.F + dx[i], u.S + dy[i]};

      if (v.F < 0 || v.F >= n || v.S < 0 || v.S >= m || A[v.F][v.S] != '.')
        continue;

      A[v.F][v.S] = A[u.F][u.S];
      if (A[u.F][u.S] == 'A')
        nex[v.F][v.S] = i;

      q.push(v);
    }
  }
  cout << "NO" << endl;
}
int32_t main() {
  fastio();
  int n = 1;
  while (n--)
    solve();
  return 0;
}

