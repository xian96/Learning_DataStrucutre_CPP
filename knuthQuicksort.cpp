/*
author: jiaxian xing
knuthpartialQuickSort
Notice: the file named "hw3.dat" located in current path.
Notice: the file must contain n numbers of int. n is changable in main(same with file int amount).
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

void readFile(string fileName, vector<int> &x)
{
    ifstream file(fileName); //open the file
    if (file.is_open())
    {
        int number;
        //        clear to initial
        x.clear();
        while (!file.eof())
        {
            if (file.eof())
                break;
            else
            {
                file >> number;
                x.push_back(number);
            }
        }
        file.close();
        //        cout << "readed\n";
    }
    else
        cout << "Unable to open file. Please check the file name or path.\n";
}

void insertionSort(vector<int> &x, int L, int R)
{
    //    cout << "TEST "<< "L:" <<L << "R:" <<R<<" ";
    int temp;
    for (int target = L + 1; target <= R; target++)
    {
        temp = x[target];
        //         cout<< "\ntemp:"<<temp;
        for (int j = target - 1; j >= L; j--)
        {
            //             cout<< "\nj:"<<j;
            //             cout<< "\nx[j]:"<<x[j];
            if (temp <= x[j])
            {
                x[j + 1] = x[j];
                if (j == L)
                    x[j] = temp;
            }
            else if (temp > x[j])
            {
                // cout<< "\nx[j]small than temp:"<<x[j]<<temp;
                x[j + 1] = temp;
                break;
            }
        }
    }
}

void partialQuickSort(vector<int> &x, int L, int R, int k)
{
    //    cout << "test pivot:"<< pivot<<" ";
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(L, R);
    //        int pivot = L + rand() % (R - L + 1);
    int pivot = distribution(generator);
    int i = L, j = R;
    while (i < j)
    {
        while (x[pivot] > x[i] && i < pivot)
            i++;
        while (x[pivot] <= x[j] && pivot < j)
            j--;
        if (i < j && x[i] > x[j])
        {
            swap(x[i], x[j]);
            if (i != pivot && j != pivot)
                ;
            else if (i == pivot && j != pivot)
                pivot = j;
            else if (i != pivot && j == pivot)
                pivot = i;
        }
    }
    //    left part
    if (pivot > L && pivot - L + 1 >= k)
        partialQuickSort(x, L, pivot, k);
    if (pivot > L && pivot - L + 1 <= k)
        insertionSort(x, L, pivot);
    //    right part
    if (R > pivot + 1 && R - pivot >= k)
        partialQuickSort(x, pivot + 1, R, k);
    if (R > pivot + 1 && R - pivot <= k)
        insertionSort(x, pivot + 1, R);
}

void krnuthQuickSort(vector<int> &x, int n, int k)
{
    if (n <= k) //means insertion
        insertionSort(x, 0, n - 1);
    else if (n > k)
        partialQuickSort(x, 0, n - 1, k);
}

void goldMeanSearch(double *data, int n)
{
    for (int i = 0; i <= n - 2; i++)
        cout << i + 2 << " " << data[i] << "\n";
    const double phi = (1 + sqrt(5)) / 2; // ~1.618
    int L = 0, R = n - 1;
    int s = (R - L) / phi;
    int x = R - s, y = L + s;
    while (R - L > 1)
    {
        if (data[x] < data[y])
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
    cout << "best time k = " << L + 2 << " took " << data[L] << " microseconds.\n";
}

void test(string fileName, vector<int> &x, int n)
{
    //creat an array to store each sort time;
    auto *time = new double[n];

    // loop to record all the k running time
    for (int k = 2; k <= n; k++)
    {
        // read to initial random number each time
        readFile(fileName, x); //for test this file contain 1 to 1000

        //        cout<<"test --------------------------------------------------------test\n";
        //        cout << "originally:\n";
        //        for (int i = 0; i <= n - 1; i++)
        //            cout << x[i] << " ";
        //        cout << "\n";

        // time
        auto t1 = chrono::steady_clock::now();
        krnuthQuickSort(x, n, k);
        auto t2 = chrono::steady_clock::now();

        // record time n[k-2];
        auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
        time[k - 2] = duration;

        //        cout << "sorted:\n";
        //        for (int i = 0; i <= n - 1; i++)
        //            cout << x[i] << " ";
        //        cout << "\n";
    }
    // gold mean search for best k;
    goldMeanSearch(time, n);
}

int main()
{
    vector<int> x; //Limited to sort int;
    int n = 1000;
    string fileName = "hw3.dat";

    test(fileName, x, n);

    // int k = 2;
    // readFile("hw3.dat", x);
    // cout << "originally:\n";
    // for (int i = 0; i <= n - 1; i++)
    //     cout << x[i] << " ";
    // cout << "\n";
    // krnuthQuickSort(x, n, k);
    // cout << "finally:\n";
    // for (int i = 0; i <= n - 1; i++)
    //     cout << x[i] << " ";
    // cout << "\n";
}