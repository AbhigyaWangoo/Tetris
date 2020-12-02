//
// Created by Abhigya Wangoo on 11/15/20.
//

#include "core/board.h"

namespace tetris {

void Board::PlaceBlock(BlockSet &block, glm::vec2& top_left) {
  //glm::vec2 updated_position = ConvertBoardCoordinate(top_left);
  if (IsOverlapping(block, top_left)) {
    throw std::runtime_error("The block is overlapping with others");
  } else if (std::find(user_board_.getUserBlocks().begin(),
                         user_board_.getUserBlocks().end(), block) == user_board_.getUserBlocks().end()) {
    throw std::runtime_error(
        "The block you clicked on wasn't part of the available blocks");
  } else {
    size_t count = 1;
    block.setBlockSetTopLeft(top_left);

    for (size_t i = 0; i < block.getBlockShape().y; i++) {
      board_[top_left.x][top_left.y + i] = true;

      while (block.isSquare() && !board_[top_left.x + i][top_left.x + i]) {
        board_[top_left.x + count][top_left.y + i] = true;
        board_[top_left.x + i][top_left.y + count] = true;
        count++;
      }

      count = 0;
    }

    for (size_t j = 0; j < block.getBlockShape().x; j++) {
      board_[top_left.x + j][top_left.y] = true;
    }

    // user_board_.erase(std::remove(user_board_.begin(), user_board_.end(),
    // block), user_board_.end()); user_blocks_.erase(block); TODO remove block
    // from user blocks after "placing" it down
  }
}

void Board::UpdateBoard() {
  if (HasLostGame()) {
    throw std::overflow_error("Game over");
  }

  user_board_.GenerateUserBlocks();

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

bool Board::IsOverlapping(const BlockSet& block, ci::vec2 top_left) {
  if (top_left.x + block.getBlockShape().x > kBoardSize ||
      top_left.y + block.getBlockShape().y > kBoardSize || top_left.x < 0 ||
      top_left.y < 0)
    return true;

  for (size_t i = top_left.y; i < block.getBlockShape().y; i++) {
    if (board_[top_left.x][i]) {
      return true;
    }
  }

  for (size_t i = top_left.x; i < block.getBlockShape().x; i++) {
    if (board_[i][top_left.y]) {
      return true;
    }
  }

  return false;
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

Board::Board() {
  std::vector<bool> row;

  for (size_t j = 0; j < kBoardSize; j++) {
    row.push_back(false);
  }

  for (size_t i = 0; i < kBoardSize; i++) {
    board_.push_back(row);
  }  // TODO Optimize
}

const UserBoard& Board::getUserBoard() const {
  return user_board_;
}

void Board::setUserBoardCoordinates(ci::vec2 &top_left, ci::vec2 &bottom_right) {
  user_board_.setTopLeft(top_left);
  user_board_.setBottomRight(bottom_right);
}

}  // namespace tetris