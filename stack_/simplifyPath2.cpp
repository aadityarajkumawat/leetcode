#include <bits/stdc++.h>
#include <string>

void showstack(std::stack <std::string> s) {
  while (!s.empty()) {
    std::cout << "  " << s.top();
    s.pop();
  }
  std::cout << '\n';
}

std::string char_str(std::string path, int i) {
  std::string s = path.substr(i, 1);
  return s;
}

std::string simplifyPath(std::string path) {
  std::stack <std::string> path_components;
  std::string curr = "";
  for (int i = 0;i < path.length();i++) {
    if (char_str(path, i) == "/") {
      path_components.push(curr);
      path_components.push(char_str(path, i));
      curr = "";
      if (i + 1 < path.length() && char_str(path, i + 1) == "/") {
        i++;
      }
    }
    else if (char_str(path, i) != "/" && char_str(path, i) != ".") {
      curr = curr + char_str(path, i);
      if (i + 1 == path.length()) {
        path_components.push(curr);
      }
    }
    else if (char_str(path, i) == ".") {
      if (i + 1 < path.length() && char_str(path, i + 1) == ".") {
        path_components.pop();
        path_components.pop();
        if (path_components.size() > 0) {
          path_components.pop();
        }
        i++;
      }
      else if (i + 1 < path.length() && char_str(path, i + 1) == "/") {
        path_components.pop();
      }
    }

    showstack(path_components);
  }

  std::string f = "";
  while (!path_components.empty()) {
    f = path_components.top() + f;
    path_components.pop();
  }
  return f;
}

int main() {
  std::string path = "/a/./b/../../c/";
  std::string canonical_path = simplifyPath(path);
  std::cout << canonical_path << std::endl;

  return 0;
}
