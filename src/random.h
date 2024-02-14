#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace Random {
inline std::mt19937 initTwister() {
  std::random_device rd{};
  std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

  std::mt19937 mt{ss};
  return mt;
}

inline std::mt19937 mt{initTwister()};

template <typename T>
inline T getRand(T from, T to) {
  std::uniform_int_distribution<T> roll{from, to};
  return roll(mt);
}
} // namespace Random

#endif
