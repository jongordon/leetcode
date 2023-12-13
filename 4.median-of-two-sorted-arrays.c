/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.55%)
 * Likes:    26925
 * Dislikes: 2964
 * Total Accepted:    2.3M
 * Total Submissions: 5.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalLength = nums1Size + nums2Size;
    int halfway = totalLength / 2;

    /* Zip merge the arrays to the halfway point (no point going further) */
    int* merged = malloc((halfway + 1) * sizeof(int));
    for (int i = 0; i < halfway + 1; ++i) {
        /* Watch out for uneven sized arrays - only compare if both arrays present */
        int a = INT_MIN, b = INT_MIN;
        if (nums1Size > 0) {
            a = nums1[0];
        }
        if (nums2Size > 0) {
            b = nums2[0];
        }

        /* Check we have compare vlaues and comapre accordingly */
        if ((a != INT_MIN) && (b != INT_MIN)) {
            if (a < b) {
                merged[i] = a;
                ++nums1;
                --nums1Size;
            } else {
                merged[i] = b;
                ++nums2;
                --nums2Size;
            }
        /* Otherwise we can simply add if only running through one array still */
        } else if (a != INT_MIN) {
            merged[i] = a;
            ++nums1;
            --nums1Size;
        } else {
            merged[i] = b;
            ++nums2;
            --nums2Size;
        }
    }

    double median = 0.0;
    if (totalLength % 2) {
        /* Odd number of elements, median is directly in the middle */
        median = (double)merged[halfway];
    } else {
        /* Even number means taking both left and right of exact centre */
        median = ((double)merged[halfway - 1] + (double)merged[halfway]) / 2.0;
    }

    /* No longer needed, free up the heap */
    free(merged);

    return median;
}
// @lc code=end

