#include "constants.h"
#include "funcs.h"
#include "random.h"
#include <iostream>
#include <string>

int main() {
  int score{0};

  while (score < Constants::wordCount) {
    int hangmanState {0};
    // TODO: remove this word from the array after it's been used once
    std::string word {Funcs::getRandomWord()};
    std::string hiddenWord {Funcs::hideLetters(word)};

    while (true) {
      Funcs::clearScreen();

      Funcs::repeatChars(Constants::numberOfDashes, Constants::defaultHR);
      std::cout << "Score: " << score << std::endl;
      Funcs::repeatChars(Constants::numberOfDashes, Constants::defaultHR);
      std::cout << hiddenWord << std::endl;
      Funcs::repeatChars(Constants::numberOfDashes, Constants::defaultHR);
      Funcs::drawHangman(hangmanState);
      Funcs::repeatChars(Constants::numberOfDashes, Constants::defaultHR);

      if (hangmanState == Constants::hangmanStateCount) {
	std::cout << "You lost! The word was: " << word << std::endl;
	break;
      } else if (hiddenWord == word) {
	std::cout << "You won!" << std::endl;
	score++;
	break;
      }

      char guess {Funcs::input<char>("Guess a letter", "\n=>")};
      std::string newHiddenWord {Funcs::revealLetter(word, hiddenWord, guess)};
      if (newHiddenWord == hiddenWord) {
	hangmanState++;
      } else {
	hiddenWord = newHiddenWord;
      }
    }
    const char yesOrNo {Funcs::input<char>("Would you like to play again? (y/n)")};
    if (yesOrNo != 'y') {
      break;
    }
  }
  return 0;
}
