#include "Insert.hpp"
#include "Szyfr_Cezara.hpp"
#include "Szyfr_Vatsayanana.hpp"
#include <iostream>

int main() {

  int choice{-1};
  std::string TextToChiper{};

  do {
    TextToChiper.clear();
    std::cout << "1. Cesar Chiper\n";
    std::cout << "2. Vatsayanana Chiper\n";
    std::cout << "0. EXIT\n";
    std::cout << "InsertNum\n>";
    std::cin >> choice;

    std::cin.ignore();
    switch (choice) {
    case 1:
      TextToChiper = InsertTextChoice();
      if (TextToChiper != " ")
        ceasar_cipher(getShift(), TextToChiper);
      break;
    case 2:
      TextToChiper = InsertTextChoice();
      if (TextToChiper != " ")
        Vatsayanan_cipher(TextToChiper);
      break;
    case 0:
      break;
    default:
      std::cout << "\nWrong Input!\n";
      break;
    }
  } while (choice != 0);

  return 0;
}
