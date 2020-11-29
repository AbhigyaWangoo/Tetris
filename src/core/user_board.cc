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

      current_block.InitializeBlock(false);
      user_blocks_.push_back(current_block);
      
      AddBlockToGrid(current_block, i, top_left_block);
    }
  }
}

void tetris::UserBoard::AddBlockToGrid(tetris::BlockSet& block, size_t count, ci::vec2 &top_left) {

  while (top_left.x + block.getBlockShape().x > grid_.size()) {
    std::vector<bool> row;
    
    for (size_t j = 0; j < kBoardSize; j++) {
      row.push_back(false);
    }

    grid_.push_back(row);
  }

  for (size_t i = top_left.x; i <= top_left.x + block.getBlockShape().x; i++) {
    grid_[i][top_left.x] = true; 
  }

  for (size_t j = top_left.y; j <= top_left.y + block.getBlockShape().y; j++) {
    grid_[top_left.y][j] = true;
  }
  
  if (block.isSquare()) {
//    for (size_t j = 0; j <= i;j++) {
//      grid_[top_left.x + j][i] = true;
//      grid_[i][top_left.y + j] = true;
//    }
  } // TODO RID THIS NESTED LOOP, THIS PORTION IS A REPITITION, MOVE INTO FUNCTION
}

tetris::UserBoard::UserBoard() {
  std::vector<bool> row;

  for (size_t j = 0; j < kBoardSize; j++) {
    row.push_back(false);
  }

  for (size_t i = 0; i < kBoardSize; i++) {
    grid_.push_back(row);
  } // TODO Optimize
}

const std::vector<std::vector<bool>>& tetris::UserBoard::getGrid() const {
  return grid_;
}
const std::vector<tetris::BlockSet>& tetris::UserBoard::getUserBlocks() const {
  return user_blocks_;
}
