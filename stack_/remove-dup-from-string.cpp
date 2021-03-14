#include <iostream>
#include <string>
#include <stack>

std::string removeDuplicates(std::string S)
{
    std::stack<char> s;
    std::string finalString = "";

    if (S.length() == 1 || S.length() == 0)
    {
        return S;
    }

    for (int i = 0; i < S.length(); i++)
    {
        if (s.empty())
            s.push(S[i]);
        else
        {
            if (s.top() == S[i])
                s.pop();
            else
                s.push(S[i]);
        }
    }

    while (!s.empty())
    {
        finalString = s.top() + finalString;
        s.pop();
    }
    return finalString;
}

int main()
{
    std::string S = "abbaca";
    std::string newS = removeDuplicates(S);

    std::cout << newS << std::endl;
    return 0;
}
