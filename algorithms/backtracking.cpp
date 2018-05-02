#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 6; // NxN board
  unsigned long long time_, timeout = 10000000;
  vector<vector<int>> sol (n, vector<int>(n, -1));

  vector<vector<int>> moves {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
  };

  int s[2] = {0, 0}; // Starting point

  function<bool(int, int)> isSafe;
  isSafe = [n, &sol](int x, int y) {
    return x > -1 && x < n && y > -1 && y < n && sol[x][y] == -1;
  };

  function<bool(int, int, int)> isPossible;
  isPossible =
  [n, moves, &sol, &isSafe, &isPossible, &time_, &timeout](int x, int y, int i) {
    if (i == (n * n)) return true;

    if (time_ > timeout) return false;

    for (int k = 0; k < 8; k++) {
      int nx = x + moves[k][0];
      int ny = y + moves[k][1];

      if (isSafe(nx, ny)) {
        sol[nx][ny] = i;

        if (isPossible(nx, ny, i + 1))
          return true;
        else
          sol[nx][ny] = -1;
      }
    }

    time_++;

    return false;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sol[i][j] = 0;
      time_ = 0;

      printf("(%d,%d)\n", i, j);
      if (isPossible(i, j, 1)) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++)
            printf(" %3d", sol[i][j]);

          printf("\n");
        }
      }
      else
        if (time_ < timeout)
          printf("Solution doesn't exist.\n");
        else
          printf("Timeout.\n");

      for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++)
          sol[k][l] = -1;

      printf("\n");
    }
  }

  return 0;
}
