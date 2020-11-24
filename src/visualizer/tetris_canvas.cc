//
// Created by Abhigya Wangoo on 10/31/20.
//

#include "visualizer/tetris_canvas.h"

#include <visualizer/tetris_app.h>

namespace tetris {
namespace visualizer {

void BoardCanvas::RenderBoard() {
  ci::vec2 top_left = ci::vec2(tetris::visualizer::kWindowSize / 6,
                               tetris::visualizer::kWindowSize / 6);
  ci::vec2 bottom_right = ci::vec2(tetris::visualizer::kWindowSize * 5 / 6,
                                   tetris::visualizer::kWindowSize * 5 / 6);
  size_t increment = (bottom_right.x - top_left.x) / kBoardSize;

  RenderGrid(increment, top_left, bottom_right);

  RenderBlocks(increment, top_left);
}

void BoardCanvas::RenderUserBlocks() {
}

void BoardCanvas::RenderBlocks(size_t increment, ci::vec2 top_left) {
  
  if (board_.getBoard().empty())
    return;
  
  else {
    for (size_t i = 0; i < kBoardSize; i++) {
      for (size_t j = 0; j < kBoardSize; j++) {
        if (board_.getBoard()[i][j]) {
          ci::vec2 block_top_left =
              ci::vec2(i * increment + top_left.x, j * increment + top_left.y);
          ci::vec2 block_bottom_right =
              ci::vec2((i + 1) * increment + top_left.x,
                       (j + 1) * increment + top_left.y);

          ci::gl::drawSolidRect(ci::Rectf(block_top_left, block_bottom_right),
                                block_top_left, block_bottom_right);

          //      Render a block in this grid spot
        }
      }
    }
  }
}

void BoardCanvas::RenderGrid(size_t increment, ci::vec2 top_left,
                             ci::vec2 bottom_right) {
  for (size_t i = 0; i < kBoardSize + 1; i++) {
    ci::gl::drawLine(ci::vec2(top_left.x + i * increment, top_left.y),
                     ci::vec2(top_left.x + i * increment, bottom_right.y));
    ci::gl::drawLine(ci::vec2(top_left.x, top_left.y + i * increment),
                     ci::vec2(bottom_right.x, top_left.y + i * increment));
  }
}

BoardCanvas::BoardCanvas(Board &board) {
  board_ = board;
}
BoardCanvas::BoardCanvas() {
}

}  // namespace visualizer

}  // Namespace tetris