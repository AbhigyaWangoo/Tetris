//
// Created by Abhigya Wangoo on 10/31/20.
//

#include "visualizer/tetris_canvas.h"

#include <visualizer/tetris_app.h>  // TODO FIGURE OUT HOW TO REMOVE THIS

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

  board_.setUserBoardCoordinates(user_blocks_top_left,
                                 user_blocks_bottom_right);

  RenderBlocks(user_blocks_top_left, user_blocks_bottom_right,
               board_.getUserBoard().getGrid());
}

void BoardCanvas::RenderBlocks(
    ci::vec2 &top_left, ci::vec2 &bottom_right,
    const std::vector<std::vector<bool>> &shaded_grid) {
  size_t increment_x = (bottom_right.x - top_left.x) / shaded_grid[1].size();
  size_t increment_y = (bottom_right.y - top_left.y) / shaded_grid.size();

  for (size_t i = 0; i < shaded_grid.size(); i++) {
    for (size_t j = 0; j < shaded_grid[i].size(); j++) {
      if (shaded_grid[i][j]) {
        ci::vec2 block_top_left = ci::vec2(j * increment_x + top_left.x,
                                           i * increment_y + top_left.y);
        ci::vec2 block_bottom_right =
            ci::vec2((j + 1) * increment_x + top_left.x,
                     (i + 1) * increment_y + top_left.y);

        if (block_bottom_right.x > bottom_right.x ||
            block_bottom_right.y > bottom_right.y) {
          throw std::runtime_error(" user_block rendered out of frame ");
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

void BoardCanvas::SelectBlock(ci::vec2 &position) {
  std::vector<BlockSet> user_blockset = board_.getUserBoard().getUserBlocks();
  ci::vec2 user_board_top_left = board_.getUserBoard().getTopLeft();
  ci::vec2 user_board_bottom_right = board_.getUserBoard().getBottomRight();
  bool passing_vertical_range = user_board_top_left.y <= position.y &&
                                user_board_bottom_right.y >= position.y;
  bool passing_horizontal_range;

  size_t count = 0;
  double increment = (kBottomRight.x - kTopLeft.x) /
                     (board_.getUserBoard().getUserBlocks().size());
  while (count < board_.getUserBoard().getUserBlocks().size()) {
    passing_horizontal_range =
        kTopLeft.x + count * increment <= position.x &&
        kTopLeft.x + (count + 1) * increment >= position.x;

    if (passing_horizontal_range && passing_vertical_range) {
      current_selected_block_ = user_blockset[count];
      break;
    } else if (!passing_horizontal_range && !passing_vertical_range) {
      throw std::runtime_error(" You haven't selected a block ");
    }

    count++;
  }
}
const BlockSet &BoardCanvas::getCurrentBlock() const {
  return current_selected_block_;
}

}  // namespace visualizer

}  // Namespace tetris