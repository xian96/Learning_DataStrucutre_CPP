// Analysis of algorithms: loops recursion, dynamic programming (memoization)
// Sorting (insertion, quicksort, heapsort, mergesort)
// Shuffling: Fischer Yates
// Searching: linear, binary, golden mean.
// Number theoretic algorithms: gcd, lcm, brute force trial division, Eratosthenes' powermod Fermat, Miller-Rabin
// GrowArray
// LinkedLists, Stacks, Queues

// You also must know trees

// Binary tree
// inorder, preorder, postorder traversal
// Trie (insert, containsWord, containsPrefix)

// (n(n+1))/2 = O(n^2)
for(int i = 0; i < n; i ++)//O(n)
{
    for(int j = i; j < n; j++)//O(n/2) = n ]
    {
        // cout;
    }
}

//  n logn
for(int i = 0; i < n; i*2)//O(log n)
{
    for(int j = i; j < n; j++)//O(n/2) = n ]
    {
        // cout;
    }
}

// 2 ^n
recursion(x)
{
    if return 1;
    else recursion(x-1) + recursion(x-2);
}

// n
recursion(x)
{
    static int memo[500] = {};
    if return 1;
    else memo[x] = recursion(x-1) + recursion(x-2);
}

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int lcm(int a, int b)
{
    return a/gcd(a,b) * b;
}

double power(x,n)
{
    double prod = 1;
    while(n > 0)
    {
        if(n %2 == 1) prod *= x;
        x *= x;
        n /= 2;
    }
    return prod;
}

double powermod(x,n,m)
{
    double prod = 1;
    while(n>0){
        if(n % 2 == 1) prod = prod * x % m;
        x  = x * x % m;
        n /= 2;
    }
    return prod;
}

bool fermat(n)
{
    for(k times)
    {
    int a = random(2,p-1);
    if(powermod(a,p-1,p) != 1) return false;
    }
    return true;
}

millerRabin(n)
{
    int s =0;
    int d = n-1;
    int mask = 1;
    while(d & mask == 0)
    {
        s++;
        d >> 1;
    }
    for(k times)
    {
        int a = random(2,n-1);
        if(powermod(a,d,n) != 1 && powermod(a,d,n) != n-1)
            return false;
        for(int j = 1; j < s-1; j++)
        {
            x = x* x % n;
            if (x == 1)
            return false;
            if(x == n-1)
             goto nexttrial;
        }
        return false;
        nextTrial;
    }
    return true;
}

