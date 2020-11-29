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
  //TODO IMPLEMENT
  return false;
}
const glm::vec2& BlockSet::getBlockCoordinate() const {
  return block_top_left_;
}

void BlockSet::InitializeBlock(bool is_square) {
  size_t x = rand() % kBoardSize / 2;
  size_t y;
  
  if (is_square) {
    y = x;  
  } else {
    y = rand() % kBoardSize / 2;
  }
  
  block_shape_ = ci::vec2(x,y);
  is_square_ = is_square;
}

}