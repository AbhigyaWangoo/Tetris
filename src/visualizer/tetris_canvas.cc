//
// Created by Abhigya Wangoo on 10/31/20.
//

#include "visualizer/tetris_canvas.h"

#include <visualizer/tetris_app.h>

namespace tetris {
namespace visualizer {

BoardCanvas::BoardCanvas(Board &board) {
  board_ = board;
}
BoardCanvas::BoardCanvas() {
}

void BoardCanvas::RenderBoard() {
  ci::vec2 top_left = ci::vec2(tetris::visualizer::kWindowWidth / 6,
                               tetris::visualizer::kWindowWidth / 6);
  ci::vec2 bottom_right = ci::vec2(tetris::visualizer::kWindowWidth * 5 / 6,
                                   tetris::visualizer::kWindowWidth * 5 / 6);
  size_t increment = (bottom_right.x - top_left.x) / kBoardSize;

  RenderGrid(increment, top_left, bottom_right);

  RenderBlocks(increment, top_left, bottom_right, board_.getBoard());

 // RenderUserBlocks(top_left, bottom_right, increment);
}

void BoardCanvas::RenderUserBlocks(ci::vec2 &top_left, ci::vec2 &bottom_right,
                                   size_t increment) {
  ci::vec2 user_blocks_top_left =
      ci::vec2(top_left.x - increment / 2, increment / 2 + bottom_right.y);
  ci::vec2 user_blocks_bottom_right = ci::vec2(bottom_right.x + increment / 2, kWindowLength - increment / 2);

  user_blocks_.GenerateUserBlocks();

  RenderBlocks(increment, user_blocks_top_left, user_blocks_bottom_right, user_blocks_.getGrid());
}

void BoardCanvas::RenderBlocks(
    size_t increment, ci::vec2 &top_left, ci::vec2 &bottom_right,
    const std::vector<std::vector<bool>> &pre_rendered_grid) { // todo rename pre_rendered_grid
  if (board_.getBoard().empty()) {
    return;
  } else {
    size_t increment_x = (bottom_right.x - top_left.x) / kBoardSize;
    size_t increment_y = (bottom_right.y - top_left.y) / kBoardSize;
    
    for (size_t i = 0; i < pre_rendered_grid.size(); i++) {
      for (size_t j = 0; j < pre_rendered_grid[i].size(); j++) {
        if (pre_rendered_grid[i][j]) {
          ci::vec2 block_top_left =
              ci::vec2(i * increment_x + top_left.x, j * increment_y + top_left.y);
          ci::vec2 block_bottom_right =
              ci::vec2((i + 1) * increment_x + top_left.x,(j + 1) * increment_y + top_left.y);
          
          if (block_bottom_right.x > bottom_right.x || block_bottom_right.y > bottom_right.y) {
            return;
          }
          
          ci::gl::drawSolidRect(ci::Rectf(block_top_left, block_bottom_right),
                                block_top_left, block_bottom_right);

          //      Render a block in this grid spot
        }
      }
    }
  }
}

void BoardCanvas::RenderGrid(size_t increment, ci::vec2 &top_left,
                             ci::vec2 &bottom_right) {
  for (size_t i = 0; i < kBoardSize + 1; i++) {
    ci::gl::drawLine(ci::vec2(top_left.x + i * increment, top_left.y),
                     ci::vec2(top_left.x + i * increment, bottom_right.y));
    ci::gl::drawLine(ci::vec2(top_left.x, top_left.y + i * increment),
                     ci::vec2(bottom_right.x, top_left.y + i * increment));
  }
}

}  // namespace visualizer

}  // Namespace tetris