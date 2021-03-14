#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> buildArray(std::vector<int>& target, int n) {
    std::vector<int> thatList;
    std::vector<std::string> output;

    for(int i = 1;i <= n;i++) {
	thatList.push_back(i);
    }

    for(int i = 0;i < target.size();i++) {
	int j = i;
	if(target[i] != thatList[i]) {
	    while(target[i] != thatList[j]) {
		output.push_back("Pop");
		j++;
	    }
	}
	else {
	    output.push_back("Push");
	}
    }

    return output;
}

int main() {
    std::vector<int> target = { 1, 3 };
    int n = 3;
    std::vector<std::string> output = buildArray(target, n);

    std::cout << "[";
    for(int i = 0;i < output.size();i++) {
	std::cout << output[i] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}

