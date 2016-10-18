
#include <iostream>
#include <string>

using namespace std;

string s;
char letras[4] = {'a', 'e', 'r', 's'};

bool esVocal(char c) {
  return c == 'a' || c == 'e';
}

void backtrack(int n) {
  if (n < 2 ||
      ( esVocal(s[n-2]) && !esVocal(s[n-1])) ||
      (!esVocal(s[n-2]) &&  esVocal(s[n-1]))) {
    cout << s.substr(0, n) << "\n";
    if (n < 10) {
      for (int i = 0; i < 4; ++i) {
	       s[n] = letras[i];
	       backtrack(n+1);
      }
    }
  }
}

int main() {
  s = string(10, ' ');
  backtrack(0);
}