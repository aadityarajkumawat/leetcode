/**
* Practice Everyday
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream newfile;
  string n = "list.txt";
  newfile.open(n.c_str());
  if (newfile.is_open()) {
    string tp;
    while (getline(newfile, tp)) {
      cout << tp << endl;
    }
    newfile.close();
  }
  return 0;
}