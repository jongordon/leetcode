/*
 * @lc app=leetcode id=204 lang=c
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Medium (33.40%)
 * Likes:    7613
 * Dislikes: 1388
 * Total Accepted:    809.4K
 * Total Submissions: 2.4M
 * Testcase Example:  '10'
 *
 * Given an integer n, return the number of prime numbers that are strictly
 * less than n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: n = 1
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 5 * 10^6
 *
 *
 */

// @lc code=start

#include <stdlib.h>
#include <math.h>

int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }

    /* Sieve of Eratosthenes is the only optimal solution given the cosntraints
        (up to n = 5,000,000) */

    /* Create an array of all the integers from 0...n that can be candidates for primes */
    int* primes = malloc(n * sizeof(int));
    primes[0] = -1;
    primes[1] = -1;
    for (int i = 2; i < n; ++i) {
        primes[i] = i;
    }

    /* Loop thorugh integers until sqrt(n) as all multiples after this point have been handled by
        smaller multiples from previous primes */
    int limit = sqrt(n);    /* Optimise this calculation */
    for (int i = 2; i <= limit; /* Loop will determine i for next iteration */) {
        /* Find this prime's multiples (starting a i^2 as smaller multiples, again,
            will have been coverd by previous primes) */
        for (int j = (i * i); j < n; j += i) {
            primes[j] = -1;
        }

        /* Now find the next none-marked (i.e., prime) number */
        int next;
        for (next = i + 1; next < n; ++next) {
            if (primes[next] != -1) {
                i = primes[next];
                break;
            }
        }
        if (next == n) {
            /* No more primes */
            break;
        }
    }

    /* Now simply count the number of non-sentinels (-1) left in primes */
    int sumPrimes = 0;
    for (int i = 2; i < n; ++i) {
        if (primes[i] != -1) {
            ++sumPrimes;
        }
    }

    return sumPrimes;
}
// @lc code=end

