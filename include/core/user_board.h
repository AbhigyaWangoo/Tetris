//
// Created by Abhigya Wangoo on 11/25/20.
//

#ifndef TETRIS_USER_BOARD_H
#define TETRIS_USER_BOARD_H

#include <vector>

#include "block_set.h"

namespace tetris {

/**
 * Global variables
 */
const static double kWindowWidth = 600;
const static double kWindowLength = 1000;
const ci::vec2 kTopLeft = ci::vec2(kWindowWidth / 6, kWindowWidth / 6);
const ci::vec2 kBottomRight =
    ci::vec2(kWindowWidth * 5 / 6, kWindowWidth * 5 / 6);
const static size_t kIncrement = (kBottomRight.x - kTopLeft.x) / kBoardSize;

/**
 * Class representing the block sets available to the user
 */
class UserBoard {
 public:
  /**
   * Empty constructor for the UserBoard, initializes empty grid
   */
  UserBoard();

  /**
   * Generates the block sets for the player to use
   */
  void GenerateUserBlocks();

  /**
   * Finds the grid values of the user block sets
   *
   * @return grid of the user block sets
   */
  const std::vector<std::vector<bool>> &getGrid() const;

  /**
   * Returns the set of block sets belonging to the user
   *
   * @return vector of BlockSets
   */
  const std::vector<BlockSet> &getUserBlocks() const;

  /**
   * Sets the top left coordinate of the top left of the user_board
   *
   * @param topLeft coordinate
   */
  void setTopLeft(const glm::vec2 &topLeft);

  /**
   * Sets bottom right coordinate of the bottom right of the user_board
   *
   * @param bottomRight coordinate
   */
  void setBottomRight(const glm::vec2 &bottomRight);

  /**
   * Finds the top left coordinate of the user_board
   *
   * @return the top left coordinate
   */
  const glm::vec2 &getTopLeft() const;

  /**
   * Returns the bottom right coordinate of the user_board
   *
   * @return the coordinates of the user_board
   */
  const glm::vec2 &getBottomRight() const;

  /**
   * Removes a particular block from the user_blocks_
   *
   * @param block_set to remove
   */
  void RemoveBlock(BlockSet &block_set);

 private:
  ci::vec2 top_left_;
  ci::vec2 bottom_right_;
  std::vector<BlockSet> user_blocks_;
  std::vector<std::vector<bool>> grid_;

  /**
   * Adds a block_set to the visual representation of the user's block_set sets
   *
   * @param block_set to add to grid
   * @param is_adding_blocks to indicate whether we're removing or adding a
   * block_set to a grid
   * @param is_adding_blocks to determine whether we're adding to or removing
   * from the grid
   */
  void AddOrRemoveBlockFromGrid(BlockSet &block_set, ci::vec2 &top_left,
                                bool is_adding_blocks);
};

}  // namespace tetris

#endif  // TETRIS_USER_BOARD_H
