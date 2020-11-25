//
// Created by Abhigya Wangoo on 11/25/20.
//

#include "core/user_board.h"
void tetris::UserBoard::GenerateUserBlocks() {
  Block current_block;

  if (user_blocks_.empty()) {
    for (size_t i = 0; i < kUserBlockCount; i++) {
      current_block.InitializeBlock(false);
      user_blocks_.push_back(current_block);

      AddBlockToGrid(current_block, i);
    }
  }
}
void tetris::UserBoard::AddBlockToGrid(tetris::Block& block, size_t count, size_t increment) {

//  for (size_t i = top_left.x; i <= block.getBlockShape().x; i++) {
//    board_[top_left.x][i] = true;
//    for (size_t j = top_left.y; j <= block.getBlockShape().y; j++) {
//      board_[j][top_left.y] = true;
//    }
//
//    if (block.isSquare()) {
//      for (size_t j = 0; j <= i;j++) {
//        board_[top_left.x + j][i] = true;
//        board_[i][top_left.y + j] = true;
//      }
//    }
//  }
  
  for (size_t i = 0; i < block.getBlockShape().x; i++) {
    for (size_t j = 0; j < block.getBlockShape().y; j++) {
      
    }
  }
}
