#include <iostream>
#include <string>
#include <stack>

bool backspaceCompare(std::string S, std::string T)
{
    std::stack<char> stack_s;
    std::stack<char> stack_t;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '#' && !stack_s.empty())
        {
            stack_s.pop();
        }
        else if (S[i] != '#')
        {
            stack_s.push(S[i]);
        }
    }
    for (int i = 0; i < T.size(); i++)
    {
        if (T[i] == '#' && !stack_t.empty())
        {
            stack_t.pop();
        }
        else if (T[i] != '#')
        {
            stack_t.push(T[i]);
        }
    }

    std::string final_s = "";
    std::string final_t = "";

    while (!stack_s.empty())
    {
        final_s = stack_s.top() + final_s;
        stack_s.pop();
    }

    while (!stack_t.empty())
    {
        final_t = stack_t.top() + final_t;
        stack_t.pop();
    }

    return final_s == final_t;
}

int main()
{
    std::cout << backspaceCompare("ab#c", "ad#c") << std::endl;
    return 0;
}