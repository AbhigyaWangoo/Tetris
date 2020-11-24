//
// Created by Abhigya Wangoo on 11/15/20.
//

#include "core/board.h"

namespace tetris {

void Board::GenerateUserBlocks() {
  Block current_block;

  if (user_blocks_.empty()) {
    for (size_t i = 0; i < kUserBlockCount; i++) {
      current_block.InitializeBlock(false);
      user_blocks_.push_back(current_block);
    }
  }
}

void Board::PlaceBlock(Block& block, glm::vec2& top_left) {
  if (!IsOverlapping(block, top_left)) {
    throw std::runtime_error("The block is overlapping with others");
  } else {
    for (size_t i = top_left.x; i <= block.getBlockShape().x; i++) {
      board_[top_left.x][i] = true;
      board_[i][top_left.y] = true;
      
      if (block.isSquare()) {
        for (size_t j = 0; j <= i;j++) {
          board_[top_left.x + j][i] = true;
          board_[i][top_left.y + j] = true;
        }
      }
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

bool Board::IsOverlapping(Block& block, ci::vec2 top_left) {
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
  
  if (top_left.x + block.getBlockShape().x > kBoardSize || top_left.y + block.getBlockShape().y > kBoardSize)
    return false;
  
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
const std::vector<std::vector<bool>>& Board::getBoard() const {
  return board_;
}
const std::vector<Block>& Board::getUserBlocks() const {
  return user_blocks_;
}

Board::Board() {
  std::vector<bool> row;

  for (size_t j = 0; j < kBoardSize ; j++) {
    row.push_back(false);
  }
  
  for (size_t i = 0; i < kBoardSize ; i++) {
    board_.push_back(row);
  } // TODO Optimize
}

}  // namespace tetris