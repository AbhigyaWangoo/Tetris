//
// Created by Abhigya Wangoo on 11/15/20.
//

#include "core/board.h"

namespace tetris {

void Board::GenerateUserBlocks() {
  Block current_block;

  if (user_blocks_.empty()) {
    for (size_t i = 0; i < kUserBlockCount; i++) {
      current_block.InitializeBlock(kBoardSize, false);
      user_blocks_.push_back(current_block);
    }
  }
}

void Board::PlaceBlock(Block& block, glm::vec2& top_left) {
  if (CheckOverlap(block, top_left)) {
    throw std::runtime_error("The block is overlapping with others");
  } else {
    // Place the block in the appropriate area within the vector<Block>
    for (size_t i = top_left.x; i < block.getBlockShape().x; i++) {
      board_[top_left.x][i] = false;
    }

    for (size_t i = top_left.y; i < block.getBlockShape().y; i++) {
      board_[i][top_left.y] = false;
    }

    // user_blocks_.erase(block); TODO remove block from user blocks after
    // "placing" it down
  }
}

void Board::UpdateBoard() {
  if (HasLostGame()) {
    throw std::overflow_error("Game over");
  }

  for (size_t i = 0; i < kBoardSize; i++) {
    if (CheckFullRow(i, true)) {
      RemoveRow(i, true);
    } else if (CheckFullRow(i, false)) {
      RemoveRow(i, false);
    }
  }
}

bool Board::HasLostGame() {
  // Find out whether the existing board is positioned so that the user can't
  // place any blocks down
  return false;
}

bool Board::CheckOverlap(Block& block, ci::vec2 top_left) {
  for (size_t i = top_left.x; i < block.getBlockShape().x; i++) {
    if (board_[top_left.x][i]) {
      return false;
    }
  }

  for (size_t i = top_left.y; i < block.getBlockShape().y; i++) {
    if (board_[i][top_left.y]) {
      return false;
    }
  }

  return true;
}

bool Board::CheckFullRow(size_t row, bool is_horizontal) {
  for (size_t i = 0; i < kBoardSize; i++) {
    if ((!board_[row][i] && is_horizontal) ||
        (!board_[i][row] && !is_horizontal)) {
      return false;
    }
  }

  return true;
}

void Board::RemoveRow(size_t row, bool is_horizontal) {
  for (size_t i = 0; i < kBoardSize; i++) {
    if (is_horizontal) {
      board_[row][i] = false;
    } else {
      board_[i][row] = false;
    }
  }
}

}  // namespace tetris