/*
 * @lc app=leetcode id=150 lang=c
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (48.26%)
 * Likes:    6834
 * Dislikes: 1002
 * Total Accepted:    835.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * You are given an array of strings tokens that represents an arithmetic
 * expression in a Reverse Polish Notation.
 *
 * Evaluate the expression. Return an integer that represents the value of the
 * expression.
 *
 * Note that:
 *
 *
 * The valid operators are '+', '-', '*', and '/'.
 * Each operand may be an integer or another expression.
 * The division between two integers always truncates toward zero.
 * There will not be any division by zero.
 * The input represents a valid arithmetic expression in a reverse polish
 * notation.
 * The answer and all the intermediate calculations can be represented in a
 * 32-bit integer.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 *
 * Example 2:
 *
 *
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 *
 * Example 3:
 *
 *
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tokens.length <= 10^4
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
 * range [-200, 200].
 *
 *
 */

// @lc code=start

#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    /* Clearly a stack style question: RPN means taking two numbers and applying an operator to them.
        If there are more than two numbers consecutively, the idea is to keep going until an operator is seen
        and work on the previous two, replacing them with one answewr, and so on until the end of the string.
    */
    /* We only need to keep track of integers seen - operators perform an action and don't need tracking */
    int *stack = malloc(tokensSize * sizeof(*stack));
    int next = 0;
    int value = 0;

    for (int i = 0; i < tokensSize; ++i) {
        /* Check for operator, being mindful of '-' and negative integer */
        if ((tokens[i][0] == '+') ||
            (tokens[i][0] == '*') ||
            (tokens[i][0] == '/') ||
            (tokens[i][0] == '-' && strlen(tokens[i]) == 1)) {
            /* Order is important, oldest value first */
            int a = stack[next - 2];
            int b = stack[next - 1];
            next -= 2;

            /* Perform operation */
            switch (tokens[i][0]) {
                case '+':
                    value = a + b;
                break;
                case '-':
                    value = a - b;
                break;
                case '*':
                    value = a * b;
                break;
                case '/':
                    value = a / b;
                break;
            }
        }
        else {
            /* Interpet number and push to stack */
            value = atoi(tokens[i]);
        }

        stack[next++] = value;
    }

    return stack[--next];
}
// @lc code=end

