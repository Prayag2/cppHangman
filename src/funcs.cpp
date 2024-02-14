#include "constants.h"
#include "funcs.h"
#include "random.h"
#include <iostream>
#include <string_view>

namespace Funcs {
  void repeatChars(const int count, const char c) {
    for (int i{0}; i < count; i++) {
      std::cout << c;
    }
    std::cout << std::endl;
  }

  std::string hideLetters(const std::string_view word) {
    std::string hiddenWord {word};
    const std::size_t lettersToHide {word.size()-static_cast<std::size_t>(Constants::lettersToKeep)};
    for (std::size_t i {0}; i < lettersToHide; i++) {
      const std::size_t randomIndex {Random::getRand<std::size_t>(0, lettersToHide)};

      // If the selected index has already been hidden, skip
      if (hiddenWord[randomIndex] != Constants::hiddenChar) {
	hiddenWord[randomIndex] = Constants::hiddenChar;
      }
    }

    return hiddenWord;
  }

  std::string revealLetter(const std::string_view originalWord, const std::string_view modifiedWord, const char letter) {
    std::string newWord {modifiedWord};
    for (std::size_t i {0}; i < originalWord.size(); i++) {
      if (originalWord[i] == letter && modifiedWord[i] != letter) {
	newWord[i] = letter;
	break;
      };
    }
    return newWord;
  }

  std::string getRandomWord() {
    return Constants::words[Random::getRand(0, Constants::wordCount-1)];
  }

  void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
  }

  void drawHangman(const int hangmanState) {
    if (hangmanState == 0) {
      std::cout << Constants::aliveHangman << std::flush;
    }
    for (int i {0}; i < hangmanState; i++) {
      std::cout << Constants::hangmanStates[i] << std::flush;
    }
    std::cout << std::endl;
  }
}
