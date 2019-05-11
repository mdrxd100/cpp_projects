#include <iostream>
#include <vector>

using namespace std;

int main() {
  int robot = 0, amount, cases;
  string command;
  vector<int> results, positions;
  cin >> amount;
  for (int i = 0; i < amount; ++i) {
    cin >> cases;
    cin.ignore();
    for (int i = 0; i < cases; i++) {
      getline(cin, command);
      if (command[0] == 'L') {
        --robot;
        positions.push_back(-1);
      } else if (command[0] == 'R') {
        ++robot;
        positions.push_back(1);
      } else {
        robot += positions[command[8] - '0' - 1];
        positions.push_back(positions[command[8] - '0' - 1]);
      }
    }
    results.push_back(robot);
    robot = 0;
    positions.clear();
  }
  for (int i = 0; i < amount; ++i) {
    cout << results[i] << " ";
  }
  return 0;
}
