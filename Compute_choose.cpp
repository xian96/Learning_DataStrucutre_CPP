/*
author: jiaxian xing
HW1b: Compute choose(n,r)
 */
#include <iostream>
#include <random>
using namespace std;

double choose(int n, int r) {
    static double memo[500][500] = {0};
    if(memo[n][r] != 0) return memo[n][r];
    if(n == 0) {memo[n][r]=1; return memo[n][r];}
    if(r == 0) {memo[n][r]=1; return memo[n][r];}
    if(n == r) {memo[n][r]=1; return memo[n][r];}
    else {memo[n][r] = choose(n-1,r-1) + choose(n-1,r);
        return memo[n][r];
    }
}

int main() {
    int numTrials = 100000000;
    //  cin >> numTrials;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,500);

    for (int i = 0; i < numTrials; i++) {
        int n = distribution(generator);
        uniform_int_distribution<int> rdist(0,n);
        int r = rdist(generator);
        choose(n,r);
    }
}