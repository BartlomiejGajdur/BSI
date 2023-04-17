#include <iostream>
#include <map>
#include <string>

void Vatsayanan_cipher(std::string message) {
  std::string encoded_message;
  std::map<char, std::string> TableToCrypt = {
      {'0', "37 38"}, {'1', "38 39"}, {'2', "39 40"}, {'3', "40 41"},
      {'4', "41 42"}, {'5', "42 43"}, {'6', "43 44"}, {'7', "44 45"},
      {'8', "45 46"}, {'9', "46 47"}, {' ', "00 00"}, {'.', "00 01"},
      {',', "00 02"}, {';', "00 03"}, {':', "00 04"}, {'!', "00 05"},
      {'?', "00 06"}, {'-', "00 07"}, {'_', "00 08"}, {'\'', "00 09"},
      {'"', "00 10"}, {'(', "00 11"}, {')', "00 12"}, {'[', "00 13"},
      {']', "00 14"}, {'{', "00 15"}, {'}', "00 16"}, {'@', "00 17"},
      {'#', "00 18"}, {'$', "00 19"}, {'%', "00 20"}, {'&', "00 21"},
      {'*', "00 22"}, {'+', "00 23"}, {'/', "00 24"}, {'\\', "00 25"},
      {'^', "00 26"}, {'`', "00 27"}, {'|', "00 28"}, {'~', "00 29"},
      {'<', "00 30"}, {'>', "00 31"}, {'=', "00 32"}, {' ', "00 33"},
      {'A', "11 05"}, {'B', "12 06"}, {'C', "13 07"}, {'D', "14 08"},
      {'E', "15 09"}, {'F', "16 10"}, {'G', "17 11"}, {'H', "18 12"},
      {'I', "19 13"}, {'J', "20 14"}, {'K', "21 15"}, {'L', "22 16"},
      {'M', "23 17"}, {'N', "24 18"}, {'O', "25 19"}, {'P', "26 20"},
      {'Q', "27 21"}, {'R', "28 22"}, {'S', "29 23"}, {'T', "30 24"},
      {'U', "31 25"}, {'V', "32 26"}, {'W', "33 01"}, {'X', "34 02"},
      {'Y', "35 03"}, {'Z', "36 04"}, {'a', "01 11"}, {'b', "02 12"},
      {'c', "03 13"}, {'d', "04 14"}, {'e', "05 15"}, {'f', "06 16"},
      {'g', "07 17"}, {'h', "08 18"}, {'i', "09 19"}, {'j', "10 20"},
      {'k', "11 21"}, {'l', "12 22"}, {'m', "13 23"}, {'n', "14 24"},
      {'o', "15 25"}, {'p', "16 26"}, {'q', "17 27"}, {'r', "18 28"},
      {'s', "19 29"}, {'t', "20 30"}, {'u', "21 31"}, {'v', "22 32"},
      {'w', "23 33"}, {'x', "24 34"}, {'y', "25 35"}, {'z', "26 36"}};

  std::map<std::string, char> tableToDecrpt{};
  for (auto [key, value] : TableToCrypt) {
    tableToDecrpt[value] = key;
  }

  for (char &c : message) {
    encoded_message += TableToCrypt[c] + " ";
  }

  std::cout << "Encoded message: " << encoded_message << "\n";
  int choice;
  std::cout << "\nDo you want to decode the message?: 1 -> YES\n>";

  std::cin >> choice;
  if (choice == 1) {
    std::string decoded_message;

    for (int i = 0; i < encoded_message.size(); i += 5) {
      std::string check = std::string(encoded_message.begin() + i,
                                      encoded_message.begin() + i + 5);
      i++;
      decoded_message += tableToDecrpt[check];
    }

    std::cout << "Decoded: " << decoded_message << "\n";
    system("PAUSE");
    system("cls");
  }
}
