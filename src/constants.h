#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
  inline const std::string words[] {"apple",  "banana",    "cherry",     "elderberry",
			       "imbe",   "nectarine", "strawberry", "tangerine",
			       "ugli",   "vanilla",   "watermelon", "xigua",
			       "yellow", "zucchini"};

  // I'm using carriage returns (\r) to overwrite the previous line
  inline const std::string hangmanStates[] {"   |",
				     "\n  (_)",
				     "\n   |",
				     "\r  /|",
				     "\r  /|\\",
				     "\n  /",
				     "\r  / \\"};
  inline const std::string aliveHangman {"(ᴗ˳ᴗ).zZ"};
  inline constexpr int hangmanStateCount {sizeof(hangmanStates)/sizeof(hangmanStates[0])};
  inline constexpr int wordCount {sizeof(words)/sizeof(words[0])};
  inline constexpr char hiddenChar {'_'};
  inline constexpr int lettersToKeep {2};
  inline constexpr int numberOfDashes {20};
  inline constexpr char defaultHR {'-'};
}

#endif
