#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void ceasar_cipher(int shift, std::string text) {
  std::string result = "";
  for (char c : text) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      c = (c - base + shift) % 26 + base;
    }
    result += c;
  }
  system("cls");
    std::cout << "Text to encrypt: " << text << "\n";
    std::cout << "Shift: " << shift << "\n";
    std::cout << "Encrypted text: " << result << "\n";
  system("PAUSE");
  system("cls");
}
