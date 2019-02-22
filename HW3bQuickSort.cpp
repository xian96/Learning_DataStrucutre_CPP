/*
author: jiaxian xing
quickSort
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

void readFile(string fileName, vector<int> &x, int &n)
{
    ifstream file(fileName); //open the file
    if (file.is_open())
    {
        int number, flag = true;
        while (!file.eof())
        {
            if (file.eof())
                break;
            else if (flag == true)
            {
                file >> n;
                flag = false;
            }
            else
            {
                file >> number;
//                if(number is not a element of file)
//                {
//                    cout<< x.size();
//                    for(int i =n; i< x.size()-1; i++)
//                        x.push_back(0);
//                }
                x.push_back(number);
            }
        }
        file.close();
        // cout << "the entire file content is in memory\n";
    }
    else
        cout << "Unable to open file\n";
}

int random(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void quickSort(vector<int> &x, int L, int R)
{
    //    default_random_engine generator;
    //    uniform_int_distribution<int> distribution(L+1,R-1);
    //    int pivot = distribution(generator);
    //    srand(time(NULL));
    //    int pivot = L+ rand() % (R - L) ;
    int pivot = random(L, R);
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
    if (pivot > L)
        quickSort(x, L, pivot);
    if (R > pivot + 1)
        quickSort(x, pivot + 1, R);
}

void quickSort(vector<int> &x, int n)
{
    int L = 0, R = n - 1;
    quickSort(x, L, R);
}

int main()
{
    vector<int> x;
    int n;
    readFile("hw3.dat", x, n);
    cout << "original:\n";
    for (int i = 0; i <= n - 1; i++)
        cout << x[i] << " ";

    quickSort(x, n);
    cout << "\nquickSort:\n";
    for (int i = 0; i <= n - 1; i++)
        cout << x[i] << " ";
}