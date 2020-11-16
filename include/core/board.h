//
// Created by Abhigya Wangoo on 11/15/20.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include <vector>

#include "block.h"

namespace tetris {
/**
 * Representation of a board
 */
class board {
 public:
  /**
   * Generates the blocks for the player to use
   * 
   * @param number_of_blocks to provide to the player 
   */
  void GenerateUserBlocks(size_t number_of_blocks);
  
  /**
   * Places the given block in a certain area
   * 
   * @param block to place 
   * @param top_left coordinate of the board for the block placement
   * @param bottom_right coordinate of the board for block placement
   */
  void PlaceBlock(Block &block, ci::vec2 &top_left, ci::vec2 &bottom_right);
  
  /**
   * Checks whether the player has lost the game, i.e cannot place any blocks down anymore
   * 
   * @return whether the user has lost or not 
   */
  bool HasLostGame();
  
  /**
   * Updates board to remove rows and columns, check for game's end, and new block placements
   */
  void UpdateBoard();
 private:
  /**
   * Checks whether the block placement will overlap with other blocks
   * 
   * @param block to place 
   * @param top_left coordinate of the block placement to check for 
   * @param bottom_right coordinate of the block placement to check for
   * @return whether the placement will overlap or not
   */
  bool CheckOverlap(Block &block, ci::vec2 top_left, ci::vec2 bottom_right);
  
  /**
   * Checks whether a row is full or not 
   * 
   * @param row number to check 
   * @param is_horizontal determines whether its a row or column to check
   * @return whether the given row/column is full or not
   */
  bool CheckFullRow(size_t row, bool is_horizontal);
  
  /**
   * Removes provided row from the board
   * 
   * @param row to remove
   * @param is_horizontal determines whether its a row or column to check
   */
  void RemoveRow(size_t row, bool is_horizontal);
  
  std::vector<Block> blocks_;
  std::vector<Block> user_blocks_;
};

}

#endif  // TETRIS_BOARD_H
