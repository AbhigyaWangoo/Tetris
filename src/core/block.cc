//
// Created by Abhigya Wangoo on 10/31/20.
//

#include <core/block.h>

namespace tetris {

bool Block::isSquare() const {
  return is_square_;
}

void Block::setIsSquare(bool isSquare) {
  is_square_ = isSquare;
}

const glm::vec2& Block::getBlockShape() const {
  return block_shape_;
}

bool Block::IsValidBlock() const {
  //TODO IMPLEMENT
  return false;
}
const glm::vec2& Block::getBlockCoordinate() const {
  return block_top_left_;
}

void Block::InitializeBlock(bool is_square) {
  size_t x = rand() % kBoardSize;
  size_t y;
  
  if (is_square) {
    y = x;  
  } else {
    y = rand() % kBoardSize;
  }
  
  block_shape_ = ci::vec2(x,y);
  is_square_ = is_square;
}
void Block::setIncrement(const size_t& increment) {
  Block::increment = increment;
}

}