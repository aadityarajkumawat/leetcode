#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

int convertStringToInt(std::string s);

int calPoints(std::vector<std::string> &ops)
{
    std::stack<int> stack;
    int sum = 0;
    for (int i = 0; i < ops.size(); i++)
    {
        if (ops[i] == "C")
            stack.pop();
        else if (ops[i] == "D")
            stack.push(2 * stack.top());
        else if (ops[i] == "+")
        {
            int first = stack.top();
            stack.pop();
            int second = stack.top();
            stack.push(first);
            stack.push(first + second);
        }
        else
            stack.push(convertStringToInt(ops[i]));
    }

    while (!stack.empty())
    {
        sum = sum + stack.top();
        stack.pop();
    }

    return sum;
}

int convertStringToInt(std::string s)
{
    std::stringstream conv(s);
    int x = 0;
    conv >> x;

    return x;
}

int main()
{
    std::vector<std::string> ops = {"1"};
    int x = calPoints(ops);
    std::cout << x << std::endl;
    return 0;
}
