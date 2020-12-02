//
// Created by Abhigya Wangoo on 11/25/20.
//

#ifndef TETRIS_USER_BOARD_H
#define TETRIS_USER_BOARD_H

#include <vector>

#include "block_set.h"

namespace tetris {
/**
 * Class representing the blocks available to the user
 */
class UserBoard {
 public:
  UserBoard();
  /**
   * Generates the blocks for the player to use
   */
  void GenerateUserBlocks();

  /**
   * Finds the grid values of the user blocks
   *
   * @return grid of the user blocks
   */
  const std::vector<std::vector<bool>> &getGrid() const;

  /**
   * Returns the set of blocks belonging to the user
   *
   * @return vector of BlockSets
   */
  const std::vector<BlockSet> &getUserBlocks() const;

  void setTopLeft(const glm::vec2 &topLeft);
  void setBottomRight(const glm::vec2 &bottomRight);
  const glm::vec2 &getTopLeft() const;
  const glm::vec2 &getBottomRight() const;

 private:
  ci::vec2 top_left_;
  ci::vec2 bottom_right_;
  std::vector<BlockSet> user_blocks_;
  std::vector<std::vector<bool>> grid_;

  /**
   * Adds a block to the visual representation of the user's blocks
   *
   * @param block to add to grid
   * @param count to indicate the position of the block on the grid
   * @param increment to indicate the size of the blocks
   */
  void AddBlockToGrid(BlockSet &block, size_t count, ci::vec2 &top_left);
};

}  // namespace tetris

#endif  // TETRIS_USER_BOARD_H
