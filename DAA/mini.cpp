
/*
    Assignment: Matrix Multiplication and Multithreaded Matrix Multiplication
    Method 1: Single-threaded matrix multiplication
    Method 2: Multithreaded matrix multiplication using one thread per row
*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include <functional>
using namespace std;
using namespace chrono;

class MatrixMultiplier {
public:
    // Normal matrix multiplication using one thread
    static vector<vector<int>> normalMultiply(
        const vector<vector<int>>& A,
        const vector<vector<int>>& B,
        int rowsA, int colsA, int colsB) {

        vector<vector<int>> C(rowsA, vector<int>(colsB, 0));

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return C;
    }

    // Calculates one complete row of the result matrix
    static void multiplyRow(
        const vector<vector<int>>& A,
        const vector<vector<int>>& B,
        vector<vector<int>>& C,
        int row, int colsA, int colsB) {

        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[row][j] += A[row][k] * B[k][j];
            }
        }
    }

    // Multithreaded multiplication: one thread per row
    static vector<vector<int>> parallelMultiply(
        const vector<vector<int>>& A,
        const vector<vector<int>>& B,
        int rowsA, int colsA, int colsB) {

        vector<vector<int>> C(rowsA, vector<int>(colsB, 0));
        vector<thread> threads;

        for (int i = 0; i < rowsA; i++) {
            threads.emplace_back(
                multiplyRow,
                cref(A), cref(B), ref(C),
                i, colsA, colsB
            );
        }

        // Wait until every thread has completed
        for (int i = 0; i < rowsA; i++) {
            threads[i].join();
        }

        return C;
    }

    // Displays a matrix
    static void displayMatrix(const vector<vector<int>>& M) {
        for (const auto& row : M) {
            for (int value : row) {
                cout << setw(6) << value;
            }
            cout << '\n';
        }
    }
};

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rowsA >> colsA;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> rowsB >> colsB;

    if (rowsA <= 0 || colsA <= 0 ||
        rowsB <= 0 || colsB <= 0) {
        cout << "Invalid matrix dimensions.\n";
        return 1;
    }

    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible.\n";
        return 1;
    }

    vector<vector<int>> A(rowsA, vector<int>(colsA));
    vector<vector<int>> B(rowsB, vector<int>(colsB));

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    // Measure single-threaded execution time
    auto start1 = high_resolution_clock::now();

    vector<vector<int>> C1 =
        MatrixMultiplier::normalMultiply(
            A, B, rowsA, colsA, colsB);

    auto end1 = high_resolution_clock::now();

    double time1 =
        duration<double, micro>(end1 - start1).count();

    // Measure multithreaded execution time
    auto start2 = high_resolution_clock::now();

    vector<vector<int>> C2 =
        MatrixMultiplier::parallelMultiply(
            A, B, rowsA, colsA, colsB);

    auto end2 = high_resolution_clock::now();

    double time2 =
        duration<double, micro>(end2 - start2).count();

    cout << "\nResult using normal multiplication:\n";
    MatrixMultiplier::displayMatrix(C1);

    cout << "\nResult using multithreaded multiplication:\n";
    MatrixMultiplier::displayMatrix(C2);

    cout << fixed << setprecision(2);

    cout << "\nSingle-threaded execution time: "
         << time1 << " microseconds\n";

    cout << "Multithreaded execution time: "
         << time2 << " microseconds\n";

    if (time2 < time1) {
        cout << "Multithreaded multiplication was faster.\n";
    } else if (time2 > time1) {
        cout << "Single-threaded multiplication was faster.\n";
    } else {
        cout << "Both methods took approximately equal time.\n";
    }

    return 0;
}
