/*!
 * Knight's Tour
 * Brute-force implementation
 *
 * @author  Wisnu Adi Nurcahyo
 * @license The MIT License
 */

#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Chessboard NxN
  int n = 8;

  // Knight's legal moves
  vector<vector<int>> board (n, vector<int>(n, 0));

  /*! Knight's move checker
   * I.S: -
   * F.S: Return true if the Knight could be moved to (x, y) point.
   *      Otherwise, false.
   */
  function<bool(int, int)> moveable = [n](int x, int y) {
    return x > -1 && x < n && y > -1 && y < n;
  };

  /*! Chessboard visits checker
   * I.S: -
   * F.S: Return true if the board at the (x, y) point has been visited.
   *      Otherwise, false.
   */
  function<bool(int, int)> visited = [&board](int x, int y) {
    return board[x][y] > 0;
  };

  /*! Chessboard initialization helper
   * I.S: Current chessboard state
   * F.S: Reset the chessboard and fill `0` on the each grid.
   */
  function<void()> initializeBoard = [n, &board]() {
    vector<vector<int>> v (n, vector<int>(n, 0));

    board = v;
  };

  /*! Chessboard printer
   * I.S: -
   * F.S: Print out the chessboard state with a pretty print format.
   */
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

  int checker = 0;
  int limit = 20;
  clock_t start = clock();

  /*! Convert a microseconds to a seconds
   * I.S: -
   * F.S: Return the seconds form in the integer data type.
   */
  function<float(clock_t)> toSecs = [](clock_t start) {
    return (clock() - start) / 1000000.0;
  };

  /*! Timeout checker
   * I.S: The running tour with a defined time limit.
   * F.S: Return true if the limit passed. Otherwise, false.
   */
  function<bool(clock_t, int)> isTimeout = [&toSecs](clock_t start, int limit) {
    return toSecs(start) >= (limit / 1.0);
  };

  /*! Brute-force approach.
   * I.S: Blank state chessboard.
   * F.S: `checker = n * n` if the Knight's tour could be performed.
   *      Otherwise, `checker != n * n`. Chessboard has been filled out.
   */
  function<void(int, int, int)> tour =
  [
    n,
    limit,
    &board,
    &checker,
    &isTimeout,
    &moveable,
    &start,
    &tour,
    &visited
  ](int x, int y, int i) {
    if (!moveable(x, y) || visited(x, y) || isTimeout(start, limit)) return;

    board[x][y] = i;
    checker = i;

    ++i;
    tour(x + 1, y + 2, i);
    tour(x + 2, y + 1, i);
    tour(x - 1, y + 2, i);
    tour(x + 1, y - 2, i);
    tour(x - 2, y + 1, i);
    tour(x + 2, y - 1, i);
    tour(x - 2, y - 1, i);
    tour(x - 1, y - 2, i);

    if (checker < n * n) board[x][y] = 0;
  };

  // Find all solutions from each legal starting point
  function<void()> findAllSolutions =
  [
    n,
    limit,
    &board,
    &checker,
    &initializeBoard,
    &isTimeout,
    &printBoard,
    &start,
    &toSecs,
    &tour
  ]() {
    // Used for stats
    int fails = 0;
    int success = 0;
    clock_t total = clock();

    printf(" There are %d starting points.\n", n * n);
    printf(" Finding the solution from each starting point...\n");
    printf("\n");

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        checker = 0;
        start = clock();

        printf(" (%d, %d)\n", i, j);
        tour(i, j, 1);

        if (checker == n * n) {
          printBoard();
          success++;
        }
        else {
          fails++;
          if (!isTimeout(start, limit))
            printf(" Solution doesn't exist.\n");
          else
            printf(" Timeout.\n");
        }

        initializeBoard();

        printf("\n");
      }
    }

    printf(" Took about %.2f seconds.\n", toSecs(total));
    printf(" Success: %d starting point(s).\n", success);
    printf(" Failure: %d starting point(s).\n", fails);
  };

  // Find the solution from a random starting point
  function<void()> findRandomSolution =
  [
    n,
    limit,
    &board,
    &checker,
    &initializeBoard,
    &isTimeout,
    &printBoard,
    &start,
    &toSecs,
    &tour
  ]() {
    srand(time(0));

    int x, y;
    int tries = 0;
    clock_t total = clock();

    printf(" Finding a random solution from the %dx%d chessboard.\n", n, n);
    printf("\n");

    do {
      tries++;
      x = rand() % n;
      y = rand() % n;

      initializeBoard();

      start = clock();
      checker = 0;
      tour(x, y, 1);

    } while (checker != n * n && tries < n * n);

    if (tries >= n * n) {
      if (isTimeout(start, limit))
        printf(" Timeout for each possible solution.\n");
      else
        printf(" The solution doesn't exist.\n");
    }
    else {
      printf(" Found a solution at starting point");
      printf(" (%d, %d).\n", x, y);
      printBoard();
    }

    printf("\n");
    printf(" Took about %.2f seconds", toSecs(total));
    printf(" after %d", tries);

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
