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


}  // namespace tetris