/*The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix. We have discussed infix to postfix conversion. In this post, evaluation of postfix expressions is discussed.

Following is an algorithm for evaluation postfix expressions.
1) Create a stack to store operands (or values).
2) Scan the given expression and do the following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer


Example:
Let the given expression be “2 3 1 * + 9 -“. We scan all elements one by one.
1) Scan ‘2’, it’s a number, so push it to stack. Stack contains ‘2’
2) Scan ‘3’, again a number, push it to stack, stack now contains ‘2 3’ (from bottom to top)
3) Scan ‘1’, again a number, push it to stack, stack now contains ‘2 3 1’
4) Scan ‘*’, it’s an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result ‘3’ to stack. The stack now becomes ‘2 3’.
5) Scan ‘+’, it’s an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result ‘5’ to stack. The stack now becomes ‘5’.
6) Scan ‘9’, it’s a number, we push it to the stack. The stack now becomes ‘5 9’.
7) Scan ‘-‘, it’s an operator, pop two operands from stack, apply the – operator on operands, we get 5 – 9 which results in -4. We push the result ‘-4’ to the stack. The stack now becomes ‘-4’.
8) There are no more elements to scan, we return the top element from the stack (which is the only element left in a stack).*/

// C++ program to evaluate value of a postfix
// expression having multiple digit operands
#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(char *exp)
{
    // Create a stack of capacity equal to expression size
    stack<int> s;
    int i;

    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // if the character is blank space then continue
        if (exp[i] == ' ')
            continue;

        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.
        else if (isdigit(exp[i]))
        {
            int num = 0;

            // extract full number
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            // push the element in the stack
            s.push(num);
        }

        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();

            switch (exp[i])
            {
            case '+':
                s.push(val2 + val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            }
        }
    }
    return s.top();
}

// Driver code
int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}

// This code is contributed by rathbhupendra
