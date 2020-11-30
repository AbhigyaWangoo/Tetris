//
// Created by Abhigya Wangoo on 10/31/20.
//

#include <core/block_set.h>

namespace tetris {

bool BlockSet::isSquare() const {
  return is_square_;
}

void BlockSet::setIsSquare(bool isSquare) {
  is_square_ = isSquare;
}

const glm::vec2& BlockSet::getBlockShape() const {
  return block_shape_;
}

bool BlockSet::IsValidBlock() const {
  // TODO IMPLEMENT
  return false;
}
const glm::vec2& BlockSet::getBlockCoordinate() const {
  return block_top_left_;
}

void BlockSet::InitializeBlock() {
  size_t rand_factor = kBoardSize / 2;
  size_t x = rand() % rand_factor + 1;
  size_t y;
  bool is_square = x % 2 != 0;
  
  if (is_square) {
    y = x;
  } else {
    y = rand() % rand_factor + 1;
  }

  block_shape_ = ci::vec2(x, y);
  is_square_ = is_square;
}

}  // namespace tetris