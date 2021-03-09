#include <iostream>
#include <string>
#include <stack>

std::string simplifyPath(std::string path)
{
    std::stack<char> stack;
    std::string canonicalPath = "";
    stack.push(path[0]);
    for (int i = 1; i < path.length(); i++)
    {
        
    }

    if (stack.size() > 1 && stack.top() == '/')
    {
        stack.pop();
    }

    while (!stack.empty())
    {
        canonicalPath = stack.top() + canonicalPath;
        stack.pop();
    }

    return canonicalPath;
}

int main()
{
    std::string path = "/home//all/";
    std::string canonicalPath = simplifyPath(path);
    std::cout << canonicalPath << std::endl;
    return 0;
}
