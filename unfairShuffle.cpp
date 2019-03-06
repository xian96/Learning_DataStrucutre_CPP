#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

int random(int a, int b)
{
    // default_random_engine generator;
    // uniform_int_distribution<int> distribution(a, b);
    // cout << distribution(generator) << " ";
    // return distribution(generator);
    return a + rand() % (b - a + 1);
}

void unfairShuffle(int *a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int r = random(0, n - 1);
        swap(a[r], a[i]);
    }
    // cout << "test test ";
    // for (int j = 0; j < n; j++)
    //     cout << a[j] << " ";
    // cout << "\n";
}

void fairShuffle(int *a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int r = random(0, i);
        swap(a[r], a[i]);
    }
}

void distribution(int *array, double *distr, int n)
{
    for (int i = 0; i < n; i++)
        if (array[i] == 1)
            distr[i]++;
}

void print(double *a, int n, int k)
{
    for (int j = 0; j < n; j++) //
    {

        double i = a[j] / (double)k;
        cout << setprecision(2) << i << "\t";
    }
    cout << "\n";
}

int main()
{
    int n = 10;      //array length
    int k = 1000000; //try times
    int a[n];
    int b[n];
    double da[n]; //record each number show times
    double db[n];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[j] = j + 1;
            b[j] = j + 1;
        }
        unfairShuffle(a, n);
        distribution(a, da, n);
        fairShuffle(b, n);
        distribution(b, db, n);
    }

    cout << "unfair distribution:\t";
    print(da, n, k);
    cout << "  fair distribution:\t";
    print(db, n, k);
}