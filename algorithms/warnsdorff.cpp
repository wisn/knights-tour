/*!
 * Knight's Tour
 * Warnsdorff's rule implementation
 *
 * @author  Wisnu Adi Nurcahyo
 * @license The MIT License
 */

#include <bits/stdc++.h>
using namespace std;

struct neighbor {
  // c: count, i: moves index
  int c, i;

  bool operator > (neighbor const& n) const {
    return c > n.c;
  }
};

int main() {
  // Chessboard NxN
  int n = 8;

  // Chessboard first initialization
  vector<vector<int>> board (n, vector<int>(n, 0));

  // Knight's legal moves
  vector<vector<int>> moves = {
    {1, 2}, {2, 1}, {-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}
  };

  // Knight's move checker
  function<bool(int, int)> moveable = [n](int x, int y) {
    return x > -1 && y > -1 && x < n && y < n;
  };

  // Chessboard visits checker
  function<bool(int, int)> visited = [&board](int x, int y) {
    return board[x][y] > 0;
  };

  // Warnsdorff's rule implementation with Backtracking method
  function<bool(int, int, int)> tourable =
  [
    moves,
    n,
    &board,
    &moveable,
    &tourable,
    &visited
  ](int x, int y, int p) {
    // Mark the chessboard
    board[x][y] = p;

    // Found a solution
    if (p == n * n) return true;

    // Min Heap for the available neighbors
    priority_queue<neighbor, vector<neighbor>, greater<neighbor>> heap;

    // Check all possible moves
    for (int i = 0; i < moves.size(); i++) {
      int nx = x + moves[i][0];
      int ny = y + moves[i][1];

      if (moveable(nx, ny) && !visited(nx, ny)) {
        int count = 0;

        // Check all possible neighbors
        for (int j = 0; j < moves.size(); j++) {
          int mx = nx + moves[j][0];
          int my = ny + moves[j][1];

          if (moveable(mx, my) && !visited(mx, my))
            count++;
        }

        neighbor ne;
        ne.c = count;
        ne.i = i;

        heap.push(ne);
      }
    }

    if (heap.size() > 0) {
      neighbor ne = heap.top();
      int nx = moves[ne.i][0];
      int ny = moves[ne.i][1];

      if(tourable(x + nx, y + ny, p + 1))
        return true;
    }

    // No solution
    return false;
  };

  // Chessboard printer
  function<void()> printBoard = [n, &board]() {
    int maxdigit = log10(n * n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int step = board[i][j];
        int digit = log10(step);

        for (int k = 0; k < maxdigit - digit; k++)
          printf(" ");

        printf(" %d", step);

        if (j < n - 1) printf(" ");
      }

      printf("\n");
    }
  };

  // Chessboard initialization helper
  function<void()> initializeBoard = [n, &board]() {
    vector<vector<int>> v (n, vector<int>(n, 0));

    board = v;
  };

  // Return microseconds to seconds
  function<float(clock_t)> toSecs = [](clock_t start) {
    return (clock() - start) / 1000000.0;
  };

  clock_t start = clock();

  // Find all solutions from each legal starting point
  function<void()> findAllSolutions =
  [
    n,
    &initializeBoard,
    &printBoard,
    &toSecs,
    &tourable,
    &start
  ]() {
    // Used for stats
    int fails = 0;
    int success = 0;

    printf(" There are %d starting points.\n", n * n);
    printf(" Finding the solution from each starting point...\n");
    printf("\n");

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf(" (%d, %d)\n", i, j);

        if (tourable(i, j, 1)) {
          success++;
          printBoard();
        }
        else {
          fails++;
          printf(" Knight's tour solution doesn't exist.\n");
        }

        printf("\n");

        initializeBoard();
      }
    }

    printf(" Took about %.2f seconds.\n", toSecs(start));
    printf(" Success: %d starting point(s).\n", success);
    printf(" Failure: %d starting point(s).\n", fails);
  };

  // Find the solution from a random starting point
  function<void()> findRandomSolution =
  [
    n,
    &initializeBoard,
    &printBoard,
    &toSecs,
    &tourable,
    &start
  ]() {
    srand(time(0));

    int x = rand() % n;
    int y = rand() % n;
    int tries = 0;

    while (!tourable(x, y, 1) && tries < n * n) {
      tries++;

      x = rand() % n;
      y = rand() % n;

      initializeBoard();
    }

    printf(" Finding a random solution from the %dx%d chessboard.\n", n, n);
    printf("\n");

    if (tries >= n * n)
      printf(" The solution doesn't exist.\n");
    else {
      printf(" Found a solution at starting point");
      printf(" (%d, %d).\n", x, y);
      printBoard();
    }

    printf("\n");
    printf(" Took about %.2f seconds", toSecs(start));
    printf(" after %d", ++tries);

    if (tries < 2)
      printf(" try");
    else
      printf(" tries");

    printf(".\n");
  };

  /*!
   * Choose one from findAllSolutions or findRandomSolution helper.
   */

  // findAllSolutions();

  findRandomSolution();

  return 0;
}
