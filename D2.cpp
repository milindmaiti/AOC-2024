#include <fstream>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
std::string INPUT = "D2.in";

bool solveSingle(vector<int> &line) {
  bool dec;
  if (line.size() == 1) {
    return true;
  }
  for (int j = 0; j < (int)line.size() - 1; j++) {
    if (abs(line[j] - line[j + 1]) >= 1 && abs(line[j] - line[j + 1]) <= 3) {
      if (j == 0)
        dec = line[j] < line[j + 1];
      else {
        if (line[j] < line[j + 1] != dec) {
          return false;
        }
      }
    } else {
      return false;
    }
  }
  return true;
}

bool solveSingleSkip(vector<int> &line) {
  auto solveBad = [&](int bad) {
    vector<int> newLine;
    for (int i = 0; i < line.size(); i++) {
      if (i != bad)
        newLine.push_back(line[i]);
    }
    vector<int> newLine2;
    for (int i = 0; i < line.size(); i++) {
      if (i != bad + 1)
        newLine2.push_back(line[i]);
    }
    return solveSingle(newLine) || solveSingle(newLine2);
  };
  bool dec;

  if (line.size() == 1) {
    return true;
  }
  for (int j = 0; j < (int)line.size() - 1; j++) {
    if (abs(line[j] - line[j + 1]) >= 1 && abs(line[j] - line[j + 1]) <= 3) {
      if (j == 0) {
        dec = line[j] < line[j + 1];
      } else {
        if (line[j] < line[j + 1] != dec) {
          return solveBad(j) || solveBad(0);
        }
      }
    } else {
      return solveBad(j) || solveBad(0);
    }
  }
  return true;
}
int solveNoSkip(vector<vector<int>> &lines) {
  int ans = 0;
  for (int i = 0; i < lines.size(); i++) {
    ans += solveSingle(lines[i]);
  }
  return ans;
}

int solveSkip(vector<vector<int>> &lines) {
  int ans = 0;
  for (int i = 0; i < lines.size(); i++) {
    ans += solveSingleSkip(lines[i]);
  }
  return ans;
}
vector<vector<int>> readInput() {
  std::ifstream file(INPUT);
  int num;
  vector<vector<int>> allLines;
  while (file) {
    std::vector<int> currentLine;
    while (file >> num) {
      currentLine.push_back(num);
      if (file.peek() == '\n' || file.peek() == EOF) {
        break;
      }
    }
    if (currentLine.size())
      allLines.push_back(currentLine);
  }
  return allLines;
}
void solveB() {
  vector<vector<int>> input = readInput();
  cout << solveSkip(input) << "\n";
}
void solveA() {
  vector<vector<int>> input = readInput();
  cout << solveNoSkip(input) << "\n";
}

int main() { solveB(); }
