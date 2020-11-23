//
// Created by Abhigya Wangoo on 10/31/20.
//

#include "visualizer/tetris_canvas.h"

namespace tetris {
namespace visualizer {

void BoardCanvas::RenderBoard() {
  RenderGrid(ci::vec2(100, 100), ci::vec2(500, 500));// todo magic numbers
}

void BoardCanvas::RenderUserBlocks() {
}

void BoardCanvas::RenderBlock(Block& block, ci::vec2 top_left,
                              ci::vec2 bottom_right) {
}
void BoardCanvas::RenderGrid(ci::vec2 top_left, ci::vec2 bottom_right) {
  size_t increment = (bottom_right.x - top_left.x) / kBoardSize;
  
  for (size_t i = 0; i < kBoardSize + 1; i++) {
    ci::gl::drawLine(ci::vec2(top_left.x + i * increment, top_left.y), ci::vec2(top_left.x + i * increment, bottom_right.y));
    ci::gl::drawLine(ci::vec2(top_left.x, top_left.y + i * increment), ci::vec2(bottom_right.x, top_left.y + i * increment));
  }
}

}  // namespace visualizer
}  // Namespace tetris