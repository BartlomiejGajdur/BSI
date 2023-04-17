#include <fstream>
#include <iostream>
#include <string>

// Function for reading the text to be encrypted from a text file
std::string ReadFromFile() {
  std::ifstream plik("../TextToChiper.txt");
  std::string TextToChiper, temp;

  if (!plik) {
    std::cout << "Unable to open TextToChiper.txt!\n";
  }
  while (plik >> temp) {
    TextToChiper += temp + " ";
  }

  return TextToChiper;
}

// Function for getting the text to be encrypted from the user
std::string getTextToCipher() {
  std::string text{};
  std::cin.ignore();
  system("cls");
  std::cout << "Enter the text to be encrypted:\n>";
  std::getline(std::cin, text);
  return text;
}

// Function for getting the shift value from the user
size_t getShift() {
  size_t shift;
  system("cls");
  std::cout << "Enter Shift value:\n>";
  while (!(std::cin >> shift) || shift <= 0) {
    std::cout << "Enter a number greater than zero:\n> ";
  }
  return shift;
}

// Function for choosing the way to provide the text to be encrypted
std::string InsertTextChoice() {
  system("cls");
  size_t shift;
  std::cout << "In what way do you want to provide text to chiper?\n";
  std::cout << "1. Keyboard\n";
  std::cout << "2. File\n";
  while (!(std::cin >> shift) || shift <= 0) {
    std::cout << "Enter a number greater than zero:\n> ";
  }


  switch (shift) {
  case 1:
    return getTextToCipher();
    break;
  case 2:
    return ReadFromFile();
    break;

  default:
    std::cout << "ERROR! Insert num in range 1-2\n";
    system("PAUSE");
    system("cls");
    return "";
    break;
  }
}



