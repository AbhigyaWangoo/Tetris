//
// Created by Abhigya Wangoo on 11/25/20.
//

#include "core/user_board.h"

void tetris::UserBoard::GenerateUserBlocks() {
  BlockSet current_block;
  ci::vec2 top_left_block = ci::vec2(0, 0);

  current_block.setBlockSetTopLeft(top_left_block);
  if (user_blocks_.size() != kUserBlockCount) {
    for (size_t i = user_blocks_.size(); i < kUserBlockCount; i++) {
      top_left_block = ci::vec2(current_block.getBlockShape().x +
                                    current_block.getBlockSetTopLeft().x + 1,
                                0);

      current_block.setBlockSetTopLeft(top_left_block);
      current_block.InitializeBlock();
      user_blocks_.push_back(current_block);

      AddOrRemoveBlock(current_block, top_left_block, true);
    }
  }
}

void tetris::UserBoard::AddOrRemoveBlock(tetris::BlockSet& block,
                                       ci::vec2& top_left, bool is_adding_blocks) {
  while (top_left.x + block.getBlockShape().x > grid_[0].size()) {
    std::vector<bool> row;

    for (size_t j = 0; j < kBoardSize; j++) {
      grid_[j].push_back(false);
    }
  }

  block.setBlockSetTopLeft(top_left);

  for (size_t i = 0; i < block.getBlockShape().x; i++) {
    grid_[top_left.y][top_left.x + i] = is_adding_blocks;

    if (block.isSquare()) {
      for (size_t j = 1; j < i + 1; j++) {
        grid_[top_left.y + j][top_left.x + i] = is_adding_blocks;
        grid_[top_left.y + i][top_left.x + j] = is_adding_blocks;
      }
    }
  }

  for (size_t j = 0; j < block.getBlockShape().y; j++) {
    grid_[top_left.y + j][top_left.x] = is_adding_blocks;
  }
}

void tetris::UserBoard::RemoveBlock(tetris::BlockSet& block_set) {
  ci::vec2 block_top_left = block_set.getBlockSetTopLeft();
  BlockSet new_blockset;
  std::vector<BlockSet> new_user_blocks;
  bool has_replaced = false;

  AddOrRemoveBlock(block_set, block_top_left, false);
  new_blockset.InitializeBlock();

  for (const BlockSet &block: user_blocks_) {
    if (block_set == block && !has_replaced) {
      new_blockset.setBlockSetTopLeft(block_top_left);
      new_user_blocks.push_back(new_blockset);

      AddOrRemoveBlock(new_blockset, block_top_left, true);
      has_replaced = true;
    } else {
      new_user_blocks.push_back(block);
    }
  }

  user_blocks_ = new_user_blocks;
}

tetris::UserBoard::UserBoard() {
  std::vector<bool> row;

  for (size_t j = 0; j < kBoardSize; j++) {
    row.push_back(false);
  }

  for (size_t i = 0; i < kBoardSize; i++) {
    grid_.push_back(row);
  }
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
