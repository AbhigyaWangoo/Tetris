//
// Created by Abhigya Wangoo on 11/15/20.
//

#include "core/board.h"

namespace tetris {

Board::Board() {
  std::vector<bool> row;

  for (size_t j = 0; j < kBoardSize; j++) {
    row.push_back(false);
  }

  for (size_t i = 0; i < kBoardSize; i++) {
    grid_.push_back(row);
  }
}

const UserBoard& Board::getUserBoard() const {
  return user_board_;
}

void Board::PlaceBlock(BlockSet& block_set, glm::vec2& top_left) {
  glm::vec2 updated_position = ConvertBoardCoordinate(top_left);
  BlockSet block_set_to_remove = block_set;

  if (IsOverlapping(block_set, updated_position)) {
    throw std::runtime_error("The block_set is overlapping with others");
  } else if (std::find(user_board_.getUserBlocks().begin(),
                       user_board_.getUserBlocks().end(),
                       block_set) == user_board_.getUserBlocks().end()) {
    throw std::runtime_error(
        "The block_set you clicked on wasn't part of the available blocks");
  } else {
    block_set.setBlockSetTopLeft(updated_position);

    for (size_t i = 0; i < block_set.getBlockShape().x; i++) {
      grid_[updated_position.x][updated_position.y + i] = true;

      if (block_set.isSquare()) {
        for (size_t j = 1; j < i + 1; j++) {
          grid_[updated_position.x + j][updated_position.y + i] = true;
          grid_[updated_position.x + i][updated_position.y + j] = true;
        }
      }
    }

    for (size_t j = 0; j < block_set.getBlockShape().y; j++) {
      grid_[updated_position.x + j][updated_position.y] = true;
    }

    user_board_.RemoveBlock(block_set_to_remove);
  }
}

void Board::UpdateBoard() {
  user_board_.GenerateUserBlocks();

  for (size_t i = 0; i < kBoardSize; i++) {
    if (CheckFullRow(i, true)) {
      RemoveRow(i, true);
      player_score_++;
    } else if (CheckFullRow(i, false)) {
      RemoveRow(i, false);
      player_score_++;
    }
  }

  if (HasLostGame()) {
    throw std::range_error(" Game Over ");
  }
}

bool Board::HasLostGame() {
  for (const BlockSet& block_set : user_board_.getUserBlocks()) {
    if (HasAvailablePlacement(block_set))
      return false;
  }

  return true;
}

bool Board::IsOverlapping(const BlockSet& block, const ci::vec2& top_left) const {
  if (top_left.x + block.getBlockShape().y > kBoardSize ||
      top_left.y + block.getBlockShape().x > kBoardSize || top_left.x < 0 ||
      top_left.y < 0)
    return true;

  for (size_t i = top_left.y; i < block.getBlockShape().x + top_left.y; i++) {
    if (grid_[top_left.x][i]) {
      return true;
    }

    if (block.isSquare() && i > top_left.y) {
      for (size_t j = 1; j < block.getBlockShape().y; j++) {
        if (grid_[top_left.x + j][i]) {
          return true;
        }
      }
    }
  }

  for (size_t i = top_left.x; i < block.getBlockShape().y + top_left.x; i++) {
    if (grid_[i][top_left.y]) {
      return true;
    }
  }

  return false;
}

bool Board::CheckFullRow(size_t row, bool is_horizontal) {
  for (size_t i = 0; i < kBoardSize; i++) {
    if ((!grid_[row][i] && is_horizontal) ||
        (!grid_[i][row] && !is_horizontal)) {
      return false;
    }
  }

  return true;
}

void Board::RemoveRow(size_t row, bool is_horizontal) {
  for (size_t i = 0; i < kBoardSize; i++) {
    if (is_horizontal) {
      grid_[row][i] = false;
    } else {
      grid_[i][row] = false;
    }
  }
}
const std::vector<std::vector<bool>>& Board::getBoard() const {
  return grid_;
}

void Board::setUserBoardCoordinates(ci::vec2& top_left,
                                    ci::vec2& bottom_right) {
  user_board_.setTopLeft(top_left);
  user_board_.setBottomRight(bottom_right);
}

glm::vec2 Board::ConvertBoardCoordinate(const glm::vec2& board_coordinate) const {
  glm::vec2 new_position;
  new_position =
      ci::vec2(std::floor((board_coordinate.y - kTopLeft.y) / kIncrement),
               std::floor((board_coordinate.x - kTopLeft.x) / kIncrement));

  return new_position;
}

bool Board::HasAvailablePlacement(const BlockSet& block_set) const {
  ci::vec2 block_set_placement;

  for (size_t i = 0; i < kBoardSize; i++) {
    for (size_t j = 0; j < kBoardSize; j++) {
      block_set_placement = ci::vec2(i, j);
      if (!IsOverlapping(block_set, block_set_placement)) {
        return true;
      }
    }
  }

  return false;
}

const size_t& Board::getPlayerScore() const {
  return player_score_;
}

}  // namespace tetris