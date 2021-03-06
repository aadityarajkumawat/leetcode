#include <iostream>
#include <vector>
#include <stack>
#include <map>

std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> answer = {};
    std::map<int, int> greaterNums;
    std::stack<int> stack;

    for (int i = 0; i < nums2.size(); i++)
    {
        while (!stack.empty() && stack.top() < nums2[i])
        {
            greaterNums[stack.top()] = nums2[i];
            stack.pop();
        }

        stack.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (greaterNums.count(nums1[i]) == 0)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(greaterNums.find(nums1[i])->second);
        }
    }

    return answer;
}

int main()
{
    std::vector<int> nums1 = {2, 4};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int> d = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < d.size(); i++)
    {
        std::cout << d[i] << std::endl;
    }
    return 0;
}
