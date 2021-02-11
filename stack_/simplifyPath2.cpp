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
  if (char_str(path, path.length() - 1) != "/") {
    path = path + "/";
  }
  for (int i = 0;i < path.length();i++) {
    if (char_str(path, i) == "/") {
      if (curr != "") {
        path_components.push(curr);
      }
      path_components.push(char_str(path, i));
      curr = "";
      if (i + 1 < path.length() && char_str(path, i + 1) == "/") {
        path_components.pop();
      }
    }
    else if (char_str(path, i) != "/" && char_str(path, i) != ".") {
      curr = curr + char_str(path, i);
      if (i + 1 == path.length()) {
        path_components.push(curr);
      }
    }
    else if (char_str(path, i) == ".") {
      //# ...
      if (i + 2 < path.length() && char_str(path, i + 1) == "." && char_str(path, i + 2) == ".") {
        path_components.push("...");
        i = i + 2;
      }
      //# ../
      if (i + 2 < path.length() && char_str(path, i + 1) == "." && char_str(path, i + 2) == "/") {
        if (path_components.size() > 4) {
          path_components.pop();
          path_components.pop();
          path_components.pop();
          std::cout << "exe" << std::endl;
        }
        // else if (path_components.size() > 2) {
        //   path_components.pop();
        //   path_components.pop();
        // }
        i++;
      }
      //# .hidden
      else if (i + 1 < path.length() && (char_str(path, i + 1) != "/" || char_str(path, i + 1) != ".")) {
        path_components.push(".");
      }
      //# ..hidden
      else if (i + 2 < path.length() && char_str(path, i + 1) == "." && (char_str(path, i + 2) != "/" || char_str(path, i + 2) != ".")) {
        path_components.push("..");
        i++;
      }
      //# ./
      else if (i + 1 < path.length() && char_str(path, i + 1) == "/") {
        if (path_components.top() != "...") {
          path_components.pop();
        }
      }
    }
    showstack(path_components);
  }

  if (path_components.top() == "/" && path_components.size() > 1) {
    path_components.pop();
  }

  std::string f = "";
  while (!path_components.empty()) {
    f = path_components.top() + f;
    path_components.pop();
  }

  return f;
}

//##       "/", "c", "/"

int main() {
  std::string path = "/a/b/../../c/";
  std::string canonical_path = simplifyPath(path);
  std::cout << canonical_path << std::endl;

  return 0;
}
