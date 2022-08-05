/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22*/

#include <bits/stdc++.h>
using namespace std;
int evaluate(string s, int x, int y)
{
    char c = s[0];
    switch (c)
    {
    case '+':
        return y + x;
        break;
    case '-':
        return y - x;
        break;
    case '*':
        return y * x;
        break;
    case '/':
        return y / x;
        break;
    }
    return -1;
}
int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    int n = tokens.size();
    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" && s.size() > 1)
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            s.push(evaluate(tokens[i], x, y));
        }
        else if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" && s.size() <= 1)
        {
            return -1;
        }
        else
        {
            int num = stoi(tokens[i]);
            s.push(num);
        }
    }
    if (s.size() > 1)
    {
        return -1;
    }
    return s.top();
}
int main()
{
    return 0;
}