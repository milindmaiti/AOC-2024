#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define si set<int>
#define usi unordered_set<int>
#define sll set<ll>
#define usll unordered_set<ll>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>

void solveA() {
  ll ans = 0;
  ll a, b;
  vi A, B;
  ifstream fin("D1.in");
  ofstream fout("D1.out");
  while (fin >> a >> b) {
    A.push_back(a);
    B.push_back(b);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  for (int i = 0; i < A.size(); i++) {
    ans += abs(A[i] - B[i]);
  }
  cout << ans << "\n";
}

void solveB() {
  ll a, b, ans = 0;
  vll A;
  map<ll, ll> B;
  ifstream fin("D1.in");
  ofstream fout("D1.out");
  while (fin >> a >> b) {
    A.push_back(a);
    B[b]++;
  }
  for (int i : A) {
    ans += i * B[i];
  }
  cout << ans << "\n";
}
int main() { solveB(); }
