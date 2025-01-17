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
  /**
   * Empty constructor
   */
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

  /**
   * Selects the current block from the user's board depending on where the user
   * clicks
   *
   * @param position to select a block from
   */
  void SelectBlock(ci::vec2 &position);

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
  void RenderGrid() const;
};
}  // namespace visualizer
}  // namespace tetris

#endif  // IDEAL_GAS_IDEAL_GAS_CANVAS_H
