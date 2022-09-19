// Light, more light

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;

    /*
     * If n has an odd number of divisors in total, the last light will be on
     * otherwise, (the total number of divisor are even) it will be off.
     * If we try to count the divisors one by one, it will give us TLE (time limit exceeded)
     
     * If a number is a perfect square, it has odd number of squares.
     * For example: 
     * divisors of 1 -> 1
     * divisors of 4 -> 1, 2, 4 
     * divisors of 9 -> 1, 3, 9
     * divisors of 16 -> 1, 2, 4, 8, 16 and so on.
     * If a number is a perfect square, then the last light will be on
     * otherwise, it will be off.
     */
    
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;

        long long int a = sqrt(n);
        if (a * a == n)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}