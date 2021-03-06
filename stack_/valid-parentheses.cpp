#include <iostream>

bool isValid(string s) {
    stack<char> st;
    st.push('*');
    for(int i = 0;i < s.length(); i++) {
	if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
	    st.push(s[i]);
	}
	else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
	    if(s[i] == ')' && st.top() == '(' && st.size() > 1)
		st.pop();
	    else if(s[i] == '}' && st.top() == '{' && st.size() > 1)
		st.pop();
	    else if(s[i] == ']' && st.top() == '[' && st.size() > 1)
		st.pop();
	    else
		return false;
	}
    }

    return st.size() == 1;
}

int main() {
    return 0;
}
