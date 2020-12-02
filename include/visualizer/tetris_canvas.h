//
// Created by Abhigya Wangoo on 10/31/20.
//

#ifndef IDEAL_GAS_IDEAL_GAS_CANVAS_H
#define IDEAL_GAS_IDEAL_GAS_CANVAS_H

#include <core/block_set.h>

#include <vector>

#include "../../../../include/cinder/app/MouseEvent.h"
#include "../core/board.h"
#include "../core/user_board.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace tetris {
namespace visualizer {
/**
 * The visualizer for the ideal gas simulation
 */
class BoardCanvas {
 public:
  BoardCanvas();

  /**
   * Constructor to initialize canvas with a specific board
   *
   * @param board to perform all renderings on
   */
  BoardCanvas(tetris::Board &board);

  /**
   * Renders Current board with highlighted tiles
   */
  void RenderBoard();

  void SelectBlock(ci::vec2 &position);

  /**
   * Assigns the current block according to the user
   *
   * @param block_set to set with
   */
  void setCurrentBlock(BlockSet &block_set);

  /**
   * Finds the current block being selected by the user
   *
   * @return current_user_block_
   */
  const BlockSet &getCurrentBlock() const;

 private:
  tetris::Board board_;
  tetris::BlockSet current_selected_block_;

  /**
   * Renders all current blocks available to the user
   *
   * @param top_left coordinate of the board so the user blocks are displayed
   * correctly
   * @param bottom_right coordinate of the board so the user blocks are
   * displayed correctly
   */
  void RenderUserBlocks();

  /**
   * Renders an individual block
   *
   * @param top_left coordinate to place the shaded_grid
   * @param bottom_right coordinate to place the shaded_grid
   * @param shaded_grid provides the pixel values to render
   */
  void RenderBlocks(ci::vec2 &top_left, ci::vec2 &bottom_right,
                    const std::vector<std::vector<bool>> &shaded_grid);

  /**
   * Renders the grid for the player to play the game on
   */
  void RenderGrid();
};
}  // namespace visualizer
}  // namespace tetris

#endif  // IDEAL_GAS_IDEAL_GAS_CANVAS_H
