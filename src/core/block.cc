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
  return block_coordinate_;
}

}