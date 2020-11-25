//
// Created by Abhigya Wangoo on 11/25/20.
//

#ifndef TETRIS_USER_BOARD_H
#define TETRIS_USER_BOARD_H

#include "block.h"

#include <vector>

namespace tetris{
/**
 * Class representing the blocks available to the user
 */
class UserBoard {
 public:
  /**
   * Generates the blocks for the player to use 
   */
  void GenerateUserBlocks();
 private:
  /**
   * Adds a block to the visual representation of the user's blocks
   * 
   * @param block to add to grid 
   * @param count to indicate the position of the block on the grid
   * @param increment to indicate the size of the blocks
   */
  void AddBlockToGrid(Block &block, size_t count, size_t increment);
  
  std::vector<Block> user_blocks_;
  std::vector<std::vector<bool>> grid_;
};

}

#endif  // TETRIS_USER_BOARD_H
