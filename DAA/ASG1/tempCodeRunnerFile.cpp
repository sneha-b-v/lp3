// Question:
// Write a non-recursive and recursive program to calculate
// Fibonacci numbers and analyze their time and space complexity.

#include <iostream>
using namespace std;

// Non-recursive Fibonacci
void fibonacciIterative(int n)
{
    int a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// Recursive Fibonacci
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Enter a non-negative number." << endl;
        return 0;
    }

    cout << "Non-recursive Fibonacci: ";
    fibonacciIterative(n);

    cout << "Recursive Fibonacci: ";
    for (int i = 0; i < n; i++)
        cout << fibonacciRecursive(i) << " ";

    cout << endl;

    return 0;
}