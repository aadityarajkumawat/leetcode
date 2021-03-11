#include <iostream>
#include <string>
#include <stack>

std::string simplifyPath(std::string path)
{
    std::stack<std::string> stack;
    std::string canonicalPath = "";

    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
            continue;

        std::string dirName = "";

        while (i < path.length() && path[i] != '/')
        {
            dirName += path[i];
            i++;
        }

        i--;

        if (dirName == ".")
            continue;
        if (dirName == "..")
        {
            if (!stack.empty())
                stack.pop();
            continue;
        }

        stack.push(dirName);
    }

    // get string answer
    while (!stack.empty())
    {
        canonicalPath = "/" + stack.top() + canonicalPath;
        stack.pop();
    }

    if (canonicalPath.length() == 0)
        return "/";

    return canonicalPath;
}

int main()
{
    std::string path = "/a/./b/../../c/";
    std::string canonicalPath = simplifyPath(path);
    std::cout << canonicalPath << std::endl;
    return 0;
}
