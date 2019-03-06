/*
author: jiaxian xing
insertion sort
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
                // cout << number << " ";
                x.push_back(number);
            }
        }
        file.close();
        // cout << "the entire file content is in memory\n";
    }
    else
        cout << "Unable to open file\n";
}

void insertionSort(vector<int> &x, int n)
{
    cout <<"test test"<< x.length;
    int L = 0, R = n - 1;
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
                if (j == 0)
                    x[0] = temp;
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

int main()
{
    vector<int> x;
    int n;
    string fileName = "./hw3.dat";
    readFile(fileName, x, n);
    cout << "original:\n";
    for (int i = 0; i <= n - 1; i++)
        cout << x[i] << " ";
    insertionSort(x, n);
    cout << "\ninsertionSort:\n";
    for (int i = 0; i <= n - 1; i++)
        cout << x[i] << " ";
}
