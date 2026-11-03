// Question:
// Write a program for analysis of Quick Sort using
// deterministic and randomized variants.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class QuickSort
{
private:
    long long comparisons;

    int partition(vector<int>& a, int low, int high)
    {
        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            comparisons++;

            if (a[j] <= pivot)
            {
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[high]);
        return i + 1;
    }

    int randomizedPartition(vector<int>& a, int low, int high)
    {
        int randomIndex = low + rand() % (high - low + 1);
        swap(a[randomIndex], a[high]);

        return partition(a, low, high);
    }

    void deterministicSort(vector<int>& a, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(a, low, high);

            deterministicSort(a, low, pivot - 1);
            deterministicSort(a, pivot + 1, high);
        }
    }

    void randomizedSort(vector<int>& a, int low, int high)
    {
        if (low < high)
        {
            int pivot = randomizedPartition(a, low, high);

            randomizedSort(a, low, pivot - 1);
            randomizedSort(a, pivot + 1, high);
        }
    }

public:
    QuickSort()
    {
        comparisons = 0;
    }

    void deterministic(vector<int> a)
    {
        comparisons = 0;
        deterministicSort(a, 0, (int)a.size() - 1);

        cout << "Deterministic Quick Sort: ";
        display(a);
        cout << "Comparisons: " << comparisons << endl;
    }

    void randomized(vector<int> a)
    {
        comparisons = 0;
        randomizedSort(a, 0, (int)a.size() - 1);

        cout << "Randomized Quick Sort: ";
        display(a);
        cout << "Comparisons: " << comparisons << endl;
    }

    void display(const vector<int>& a)
    {
        for (int value : a)
            cout << value << " ";

        cout << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Number of elements cannot be negative." << endl;
        return 0;
    }

    vector<int> a(n);

    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    srand((unsigned int)time(nullptr));

    QuickSort sorter;

    sorter.deterministic(a);
    sorter.randomized(a);

    return 0;
}