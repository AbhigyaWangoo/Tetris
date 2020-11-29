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
  ci::vec2 top_left = kTopLeft;
  ci::vec2 bottom_right = kBottomRight;

  RenderGrid();

  RenderBlocks(top_left, bottom_right, board_.getBoard());

  RenderUserBlocks();
}

void BoardCanvas::RenderUserBlocks() {
  ci::vec2 user_blocks_top_left =
      ci::vec2(kTopLeft.x - increment_ / 2, increment_ / 2 + kBottomRight.y);
  ci::vec2 user_blocks_bottom_right =
      ci::vec2(kBottomRight.x + increment_ / 2, kWindowLength - increment_ / 2);

  RenderBlocks(user_blocks_top_left, user_blocks_bottom_right,
               board_.getUserBoard());
}

void BoardCanvas::RenderBlocks(
    ci::vec2 &top_left, ci::vec2 &bottom_right,
    const std::vector<std::vector<bool>>
        &pre_rendered_grid) {  // todo rename pre_rendered_grid

  size_t increment_x = (bottom_right.x - top_left.x) / kBoardSize;
  size_t increment_y = (bottom_right.y - top_left.y) / kBoardSize;

  for (size_t i = 0; i < pre_rendered_grid.size(); i++) {
    for (size_t j = 0; j < pre_rendered_grid[i].size(); j++) {
      if (pre_rendered_grid[i][j]) {
        ci::vec2 block_top_left = ci::vec2(i * increment_x + top_left.x,
                                           j * increment_y + top_left.y);
        ci::vec2 block_bottom_right =
            ci::vec2((i + 1) * increment_x + top_left.x,
                     (j + 1) * increment_y + top_left.y);

        if (block_bottom_right.x > bottom_right.x ||
            block_bottom_right.y > bottom_right.y) {
          return;
        }

        ci::gl::drawStrokedRect(ci::Rectf(block_top_left, block_bottom_right),
                                5);
      }
    }
  }
}

void BoardCanvas::RenderGrid() {
  for (size_t i = 0; i < kBoardSize + 1; i++) {
    ci::gl::drawLine(ci::vec2(kTopLeft.x + i * increment_, kTopLeft.y),
                     ci::vec2(kTopLeft.x + i * increment_, kBottomRight.y));
    ci::gl::drawLine(ci::vec2(kTopLeft.x, kTopLeft.y + i * increment_),
                     ci::vec2(kBottomRight.x, kTopLeft.y + i * increment_));
  }
}

}  // namespace visualizer

}  // Namespace tetris