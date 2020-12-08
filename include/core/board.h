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
  /**
   * Empty constructor
   */
  Board();

  /**
   * Places the given block_set set in a certain area
   *
   * @param block_set to place
   * @param top_left coordinate of the Board for the block_set placement
   */
  void PlaceBlock(BlockSet &block_set, ci::vec2 &top_left, size_t increment);

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

  /**
   * Sets the user board's coordinates to the proper value
   *
   * @param top_left coordinate to set
   * @param bottom_right coordinate to set
   */
  void setUserBoardCoordinates(ci::vec2 &top_left, ci::vec2 &bottom_right);

  /**
   * Returns the player's current score
   *
   * @return the size_t value of the player's score
   */
  const size_t &getPlayerScore() const;

 private:
  std::vector<std::vector<bool>> grid_;
  tetris::UserBoard user_board_;
  size_t player_score_;

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
  bool IsOverlapping(const BlockSet &block, ci::vec2 &top_left);

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

  /**
   * Converts the user's clicked mouse position to proper board size coordinates
   *
   * @param board_coordinate to convert
   * @param increment of the board we're rendering
   * @return The new coordinate to manage with a 2d array
   */
  glm::vec2 ConvertBoardCoordinate(glm::vec2 &board_coordinate,
                                   size_t increment);

  /**
   * Checks to see whether the current block set has any available placements on
   * the board
   *
   * @param block_set to check
   * @return whether the set can be placed or not
   */
  bool HasAvailablePlacement(const BlockSet &block_set);
};

}  // namespace tetris

#endif  // TETRIS_BOARD_H
