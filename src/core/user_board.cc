//
// Created by Abhigya Wangoo on 11/25/20.
//

#include "core/user_board.h"

void tetris::UserBoard::GenerateUserBlocks() {
  BlockSet current_block;
  ci::vec2 top_left_block;

  if (user_blocks_.empty()) {
    for (size_t i = 0; i < kUserBlockCount; i++) {
      top_left_block = ci::vec2(current_block.getBlockShape().x * i, 0);

      current_block.InitializeBlock();
      user_blocks_.push_back(current_block);

      AddBlockToGrid(current_block, i, top_left_block);
    }
  }
}

void tetris::UserBoard::AddBlockToGrid(tetris::BlockSet& block, size_t count,
                                       ci::vec2& top_left) {
  while (top_left.x + block.getBlockShape().x > grid_.size()) {
    std::vector<bool> row;

    for (size_t j = 0; j < kBoardSize; j++) {
      row.push_back(false);
    }

    grid_.push_back(row);
  }

  block.setBlockSetTopLeft(top_left);

  for (size_t i = 0; i < block.getBlockShape().y; i++) {
    grid_[top_left.y][top_left.x + i] = true;

    if (block.isSquare()) {
      for (size_t j = 1; j < i + 1; j++) {
        grid_[top_left.y + j][top_left.x + i] = true;
        grid_[top_left.y + i][top_left.x + j] = true;
      }
    }
  }

  for (size_t j = 0; j < block.getBlockShape().x; j++) {
    grid_[top_left.y + j][top_left.x] = true;
  }
}

tetris::UserBoard::UserBoard() {
  std::vector<bool> row;

  for (size_t j = 0; j < kBoardSize; j++) {
    row.push_back(false);
  }

  for (size_t i = 0; i < kBoardSize; i++) {
    grid_.push_back(row);
  }  // TODO Optimize
}

const std::vector<std::vector<bool>>& tetris::UserBoard::getGrid() const {
  return grid_;
}
const std::vector<tetris::BlockSet>& tetris::UserBoard::getUserBlocks() const {
  return user_blocks_;
}
void tetris::UserBoard::setTopLeft(const glm::vec2& topLeft) {
  top_left_ = topLeft;
}
void tetris::UserBoard::setBottomRight(const glm::vec2& bottomRight) {
  bottom_right_ = bottomRight;
}
const glm::vec2& tetris::UserBoard::getTopLeft() const {
  return top_left_;
}
const glm::vec2& tetris::UserBoard::getBottomRight() const {
  return bottom_right_;
}
