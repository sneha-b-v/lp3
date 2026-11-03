// Question:
// Design an N-Queens matrix having the first Queen placed.
// Use backtracking to place the remaining Queens to generate
// the final N-Queens solution.

#include <iostream>
#include <vector>
using namespace std;

class NQueens
{
private:
    int n;
    vector<vector<char>> board;

    bool isSafe(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0)
        {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n)
        {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    bool solve(int row)
    {
        if (row == n)
            return true;

        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col))
            {
                board[row][col] = 'Q';

                if (solve(row + 1))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

public:
    NQueens(int size)
    {
        n = size;
        board.assign(n, vector<char>(n, '.'));
    }

    void solveProblem()
    {
        if (n < 4)
        {
            cout << "No solution for N = " << n
                 << " with the first queen fixed at (1,1)." << endl;
            return;
        }

        // Place the first queen at row 1, column 1.
        board[0][0] = 1;

        if (solve(1))
        {
            cout << "Solution:" << endl;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << board[i][j] << " ";

                cout << endl;
            }
        }
        else
        {
            cout << "No solution exists with the first queen fixed."
                 << endl;
        }
    }
};

int main()
{
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "N must be positive." << endl;
        return 0;
    }

    NQueens queens(n);
    queens.solveProblem();

    return 0;
}