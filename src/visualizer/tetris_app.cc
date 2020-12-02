#include <visualizer/tetris_app.h>

namespace tetris {
namespace visualizer {
void TetrisApp::draw() {
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);
  setWindowSize(kWindowWidth, kWindowLength);
  canvas_ = BoardCanvas(board_);
  
  canvas_.RenderBoard();

  ci::gl::drawStringCentered("Tetris",
                             glm::vec2(kWindowWidth / 2, kWindowLength / 11),
                             ci::Color("white"));
}

void TetrisApp::setup() {
//  tetris::BlockSet block_set;
//  block_set.InitializeBlock();
//  ci::vec2 coord = ci::vec2(1, 1);
//
//  try {
//    board_.PlaceBlock(block_set, coord);
//  } catch(std::runtime_error &error) {
//    std::cout << error.what();
//  }
}

void TetrisApp::update() {
  try {
    board_.UpdateBoard();
  } catch (std::exception &e) {
    e.what();
  }
}

void TetrisApp::mouseDown(ci::app::MouseEvent event) {
  ci::vec2 position = event.getPos();
  BlockSet current_block;

  if (!canvas_.HasSelectedBlock()) {
    canvas_.SelectBlock(position);
  } else {
    current_block = canvas_.getCurrentBlock();
    board_.PlaceBlock(current_block, position);
    // we're placing a block rn
  }
}

}  // namespace visualizer

}  // namespace tetris
