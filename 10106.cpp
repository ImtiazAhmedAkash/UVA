// Product

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;

    // taking input till the end of file
    while (cin >> a >> b)
    {
        // set all the elements of resultant string of size(a + b) as int 0
        string res(a.size() + b.size(), 0);

        // string b is the multiplier, we will start multiplying from the last digit of b to the first
        for (int i = b.size() - 1; i >= 0; i--)
        {
            for (int j = a.size() - 1; j >= 0; j--)
            {
                /*
                 * '0' was subtracted from the two indexes for converting the char digits into int digits.
                 * the multiplication result of the values stored in the indexes will be stored in the carry first
                 * then res[i + j + 1] will have the last digit of the carry
                 * and the remaining digit will be stored in res[i + j]
                 * res [i + j] index is the res[i + j + 1] of previous iteration.
                 * so there might be a value stored in it. and += operator was used to recalculate the value of that index.
                 */
                int carry = (a[j] - '0') * (b[i] - '0') + res[i + j + 1];
                res[i + j + 1] = carry % 10;
                res[i + j] += carry / 10;
            }
        }

        // converting the int digits in the resultant string into char digits
        for (int i = 0; i < res.size(); i++)
            res[i] += '0';

        /* 
         * clearing the leading zeroes.
         
         * for cases like, 999999999 * 00
         * normally it will give 00000000000, but the answer should be only one 0
         * in order to get only one zero, we have to erase whenever s.front == '0'
         * except for the last '0' in the above case
         
         * for cases like, 33 * 2
         * the output would be 066, as the resultant string is of size 3
         * in this case, only the first zero will be erased
         */

        while (res.front() == '0' && res.size() > 1)
            res.erase(res.begin());

        cout << res << '\n';
    }

    return 0;
}
/*
 * Algortihm
 * The two numbers can be too big even for long long integers. Thats why, we have used strings.
 * We will take input until the end of file as nothing is mentioned about the test cases.
 * The size of the resultant string would be at most the sum of two input strings.
 * For example: 22 * 3 = 66, 22 * 9 = 198, 99 * 9 = 891.

 * The multiplication will be done from the last indexes to the first. Hence, the loops were executed backwards.
 * 'b' is used as the multiplier. So, all the elements of 'a' will be multiplied by the elements of 'b' one by one.
 * Before calculating, we have to convert the string elements from char to int. So, subtract '0' from each element.
 
 * Suppose, we are multiplying 1111 * 16. 
 * First, we will multiply a[3] * b[1] and assign the result in a variable lets say 'carry'. As there can be values stored in 
 * the location in some calculations (this can happen for 2nd, 3rd or so on digits of b) (and for initial calculation
 * the resultant string contains integer 0), the value was added to carry.
 * The last digit of the 'carry' will be stored at s[5]. 
 * s[5] is the last accomodated index of the string.That means, a[j] * b[i] will be stored in s[i + j + 1].
 * The rest of the value will be stored in the previous location i.e. in s[i + j]. As there can be values stored in s[i + j],
 * += operator was used to accumulate the values.
 
 * After the calculation is done, the string contains all the elements in integer form. It will print garbage value, if printed 
 * right away. So, we need to convert those int into char. Hence, '0' was added to all of the elements of the resultant string.
 * Finally, we have cleared all the leading zeroes (for cases like 0123, it will be 123, and for multiple zeroes like 00000000
 * it will be a single zero, 0. For this latter case, we have executed the loop till the 2nd last element of the resultant string)
 */