/*
author: jiaxian xing
Eratosthenes
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void isPrime(double n){
    vector<bool>table(n+1,true);
    table[0]=false;
    table[1]=false;
    for(double j = 4; j <= n; j+=2){//remove all even
        if(table[j]) {
            table[j] = false;
        }
    }
    double sum=0;
    for(double i = 2; i <= sqrt(n); i++) //O(sqrt(n)*n)
        if(table[i]){
            for(double j = i*i; j <= n; j+=(2*i)){
                if(table[j]) {
                    table[j] = false;
                }
            }
    }
    for(int i = 0; i <= n; i++)
        if(table[i]){
            sum++;
            cout<<i<<" ";
        }
    cout << "sum:"<<sum<<endl;
}

int main (){
    double n;
    cout << "please input a single number:";
    cin >> n;
    isPrime(n);
}