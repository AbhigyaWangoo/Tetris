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

void Board::PlaceBlock(Block& block, glm::vec2& top_left,
                       glm::vec2& bottom_right) {
  if (CheckOverlap(block, top_left, bottom_right)) {
    throw std::runtime_error("The block is overlapping with others");
  } else {
    // Place the block in the appropriate area within the vector<Block>
  }
}

void Board::UpdateBoard() {
  
}

bool Board::HasLostGame() {
  return false;
}
bool Board::CheckOverlap(Block& block, ci::vec2 top_left,
                         ci::vec2 bottom_right) {
  return false;
}
bool Board::CheckFullRow(size_t row, bool is_horizontal) {
  return false;
}

void Board::RemoveRow(size_t row, bool is_horizontal) {
  if (is_horizontal) {
    for (size_t x_coordinate = 0; x_coordinate < kBoardSize; x_coordinate++) {
      // check each block per coordinate to see whether the block is overlapping
      // or not. Then, change the block into 2 new blocks or 1 reduced size
      // block, depends upon the orientation
    }
  } else {
    for (size_t y_coordinate = 0; y_coordinate < kBoardSize; y_coordinate++) {
      // check each block per coordinate to see whether the block is overlapping
      // or not. Then, change the block into 2 new blocks or 1 reduced size
      // block, depends upon the orientation
    }
  }
}

}  // namespace tetris