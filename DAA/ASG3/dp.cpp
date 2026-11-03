// Question:
// Write a program to solve a 0-1 Knapsack problem using
// dynamic programming or branch and bound strategy.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of items must be positive." << endl;
        return 0;
    }

    vector<int> weight(n), profit(n);

    cout << "Enter weights of items:" << endl;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter profits of items:" << endl;
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0)
    {
        cout << "Capacity cannot be negative." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= 0 || profit[i] < 0)
        {
            cout << "Weights must be positive and profits positive or 0."
                 << endl;
            return 0;
        }
    }

    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            dp[i][w] = dp[i - 1][w];

            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i][w],
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    cout << "Maximum profit: " << dp[n][capacity] << endl;

    cout << "Selected item numbers: ";

    int w = capacity;

    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }

    cout << endl;

    return 0;
}
//10 20 30  60 100 120   50