#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <limits>
#include <string_view>

namespace Funcs {
  using namespace std::string_view_literals;

  void repeatChars(int, char);
  void clearScreen();
  void drawHangman(const int);
  std::string hideLetters(const std::string_view);
  std::string getRandomWord();
  std::string revealLetter(const std::string_view, const std::string_view, const char);

  template <typename T>
  T input(const std::string_view msg, const std::string_view prompt = ": "sv) {
    while (true) {
      T inputVar;
      std::cout << msg << prompt;
      std::cin >> inputVar;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (!std::cin) {
	if (std::cin.eof()) {
	  exit(0);
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cerr << "Invalid Input!" << std::endl;
	continue;
      }
      return inputVar;
    }
  };

  // Don't allow string input
  template <>
  std::string input<std::string>(std::string_view, std::string_view) = delete;
} // namespace Funcs
#endif
