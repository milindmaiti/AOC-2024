#include <bits/stdc++.h>
#include <ios>
#include <string>
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

bool isNumber(char c) { return (c >= '0') && (c <= '9'); }
bool findMul(string &s, int pos) {
  if (pos + 3 >= s.size())
    return false;
  return s.substr(pos, 4) == "mul(";
}
void findOps(string &s, int pos, ll &ans) {
  ll op1 = 0, op2 = 0, i1 = 0, i2 = 0;
  while (pos < s.size() && isNumber(s[pos])) {
    op1 = 10 * op1 + s[pos] - '0';
    i1++;
    pos++;
  }
  if (pos == s.size() || s[pos] != ',' || i1 == 0)
    return;
  pos++;

  while (pos < s.size() && isNumber(s[pos])) {
    op2 = 10 * op2 + s[pos] - '0';
    i2++;
    pos++;
  }
  if (pos == s.size() || s[pos] != ')' || i2 == 0)
    return;

  ans += op1 * op2;
}

string INPUT = "D3.in";
string DONT = "don't()";
string DO = "do()";
int findEnable(string &s, int pos) {
  if (pos + DONT.size() - 1 < s.size() && s.substr(pos, DONT.size()) == DONT)
    return -1;
  if (pos + DO.size() - 1 < s.size() && s.substr(pos, DO.size()) == DO)
    return 1;
  return 0;
}
/*string INPUT = "D3sample.in";*/
string readInput() {
  ifstream fin(INPUT);
  string s;
  std::stringstream buffer;
  buffer << fin.rdbuf();
  s = buffer.str();
  return s;
}
void solveB() {
  string s = readInput();
  ll ans = 0;
  bool active = true;
  for (int i = 0; i < s.size(); i++) {
    int res = findEnable(s, i);
    if (res == 1)
      active = true;
    if (res == -1) {
      active = false;
    }
    if (active && findMul(s, i)) {
      findOps(s, i + 4, ans);
    }
  }
  cout << ans << "\n";
}
void solveA() {
  string s = readInput();
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (findMul(s, i)) {
      findOps(s, i + 4, ans);
    }
  }
  cout << ans << "\n";
}
int main() { solveB(); }
