#include <bits/stdc++.h>
#include <string>

void showstack(std::stack <char> s) {
  while (!s.empty()) {
    std::cout << s.top();
    s.pop();
  }
  std::cout << '\n';
}

std::string simplifyPath(std::string path) {
  std::stack <char> path_charcters;
  std::string canonical_path = "";
  for (int i = 0;i < path.length();i++) {
    if (path[i] == '/' && !path_charcters.empty()) {
      if (path_charcters.top() == '/') {

      }
      // ----  /.../
      else if (path_charcters.top() == '.') {
        path_charcters.pop();
        if (path_charcters.top() == '.') {
          path_charcters.pop();
          if (path_charcters.top() == '.') {
            path_charcters.push('.');
            path_charcters.push('.');
            path_charcters.push('/');
          }
          // else {
          //   path_charcters.push('.');
          // }
        }
      }
      else {
        path_charcters.push(path[i]);
      }
    }
    // * /..../
    else if (path[i] == '.' && !path_charcters.empty() && path_charcters.top() == '.') {
      if (i + 1 < path.length() && path[i + 1] == '.') {
        path_charcters.push(path[i]);
        path_charcters.push(path[i]);
        // if (i + 2 < path.length()) {
        // path_charcters.push(path[i]);
        // }
        i = i + 1;
      }
      else if (path_charcters.top() == '.' && i + 1 < path.length() && path[i + 1] != '/') {
        path_charcters.push('.');
      }
      else if (path_charcters.top() == '.' && i + 1 < path.length() && path[i + 1] == '/') {
        path_charcters.push('.');
        path_charcters.push('/');
      }
      else {
        path_charcters.pop();
        if (path_charcters.size() == 1 && path_charcters.top() == '/') {
        }
        else {
          if (path_charcters.size() > 1) {
            path_charcters.pop();
          }
          if (path_charcters.size() != 0) {
            path_charcters.pop();
          }
        }
      }
    }
    else {
      path_charcters.push(path[i]);
    }

    // showstack(path_charcters);
  }

  if (path_charcters.top() == '/' && path_charcters.size() != 1) {
    path_charcters.pop();
  }
  if (path_charcters.top() == '.' && path_charcters.size() != 1) {
    path_charcters.pop();
    if (path_charcters.top() == '.') {
      path_charcters.pop();
      if (path_charcters.top() == '.') {
        path_charcters.push('.');
        path_charcters.push('.');
      }
    }
  }

  while (!path_charcters.empty()) {
    canonical_path = path_charcters.top() + canonical_path;
    path_charcters.pop();
  }

  return canonical_path;
}

// /

int main() {
  std::string path = "/hello/../world";
  std::string canonical_path = simplifyPath(path);
  std::cout << canonical_path << std::endl;

  return 0;
}
