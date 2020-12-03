//
// Created by Abhigya Wangoo on 11/15/20.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include <vector>

#include "block_set.h"
#include "user_board.h"

namespace tetris {
/**
 * Representation of a Board
 */
class Board {
 public:
  Board();

  /**
   * Places the given block in a certain area
   *
   * @param block to place
   * @param top_left coordinate of the Board for the block placement
   */
  void PlaceBlock(BlockSet &block, ci::vec2 &top_left, size_t increment);

  /**
   * Updates Board to remove rows and columns, check for game's end, and new
   * block placements
   */
  void UpdateBoard();

  /**
   * Returns the board available on the grid
   *
   * @return board of booleans
   */
  const std::vector<std::vector<bool>> &getBoard() const;

  /**
   * Returns the user board's complete object
   *
   * @return the user_board grid
   */
  const UserBoard &getUserBoard() const;

  void setUserBoardCoordinates(ci::vec2 &top_left, ci::vec2 &bottom_right);

 private:
  std::vector<std::vector<bool>> board_;
  tetris::UserBoard user_board_;

  /**
   * Checks whether the player has lost the game, i.e cannot place any blocks
   * down anymore
   *
   * @return whether the user has lost or not
   */
  bool HasLostGame();

  /**
   * Checks whether the block placement will overlap with other blocks
   *
   * @param block to place
   * @param top_left coordinate of the block placement to check for
   * @return whether the placement will overlap or not
   */
  bool IsOverlapping(const BlockSet &block, ci::vec2 top_left);

  /**
   * Checks whether a row is full or not
   *
   * @param row number to check
   * @param is_horizontal determines whether its a row or column to check
   * @return whether the given row/column is full or not
   */
  bool CheckFullRow(size_t row, bool is_horizontal);

  /**
   * Removes provided row from the Board
   *
   * @param row to remove
   * @param is_horizontal determines whether its a row or column to check
   */
  void RemoveRow(size_t row, bool is_horizontal);

  glm::vec2 ConvertBoardCoordinate(glm::vec2 &board_coordinate, size_t increment);
};

}  // namespace tetris

#endif  // TETRIS_BOARD_H
