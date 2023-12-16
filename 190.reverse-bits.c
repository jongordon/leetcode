/*
 * @lc app=leetcode id=190 lang=c
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (56.83%)
 * Likes:    4891
 * Dislikes: 1331
 * Total Accepted:    720.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * Note:
 *
 *
 * Note that in some languages, such as Java, there is no unsigned integer
 * type. In this case, both input and output will be given as a signed integer
 * type. They should not affect your implementation, as the integer's internal
 * binary representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above, the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10111111111111111111111111111111.
 *
 *
 *
 * Constraints:
 *
 *
 * The input must be a binary string of length 32
 *
 *
 *
 * Follow up: If this function is called many times, how would you optimize it?
 *
 */

// @lc code=start

#include <stdint.h>
#include <stdbool.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 1;    /* As we move res left, if we don't start with 1, it won't move, we will correct this at the end if needed */
    bool set = n & 0x1;

    /* Already accounted first bit */
    n >>= 1;

    for (int i = 1; i < 32; ++i) {
        res <<= 1;      /* Increment at start of loop so we don't go over 32 bits */
        res |= n & 0x1; /* Copy lowest bit of n */
        n >>= 1;
    }

    /* Recall first bit and correct the '1' if needed */
    if (!set) {
        res &= ~0x80000000;
    }

    return res;
}
// @lc code=end

