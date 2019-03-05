#include <iostream>
#include <random>
#include <cmath>
using namespace std;

const double phi = (1 + sqrt(5)) / 2; // ~1.618

int goldenMeanSearch(int data[], int n)
{
    int L = 0, R = n - 1;
    int s = (R - L) / phi;
    int x = R - s, y = L + s;
    while (R - L > 1) //change the R>L to R - L > 1;
    {
        if (data[x] > data[y])
        {
            R = y;
            y = x;
            s = (R - L) / phi;
            x = R - s;
        }
        else
        {
            L = x;
            x = y;
            s = (R - L) / phi;
            y = L + s;
        }
    }
    return L;
}

int main()
{
    const double start = 0, max = 152, end = 3, noise = 1;
    const int n = 21;
    int data[n] = {1, 5, 16, 17, 18, 92, 15, 15, 12, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0};
    //	double data2[n] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2,  5, 16, 17, 18, 92, 15, 15, 12, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0};
    //	generateQuadraticList(data, n, start, max, end, noise);
    cout << goldenMeanSearch(data, n) << '\n';
}
