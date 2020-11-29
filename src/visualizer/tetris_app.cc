#include <visualizer/tetris_app.h>

namespace tetris {
namespace visualizer {
void TetrisApp::draw() {
  ci::Color8u background_color(0, 0, 0);
  ci::gl::clear(background_color);
  setWindowSize(kWindowWidth, kWindowLength);
  
  canvas_.RenderBoard();

  ci::gl::drawStringCentered("Tetris",
                             glm::vec2(kWindowWidth / 2, kWindowLength / 11),
                             ci::Color("white"));
}

void TetrisApp::setup() {
  tetris::BlockSet block_set;
  block_set.InitializeBlock(false);
  ci::vec2 coord = ci::vec2(1,1);
  
  board_.PlaceBlock(block_set, coord);
  
  canvas_ = BoardCanvas(board_); // TODO We need a way to update the board_ in the canvas with the board with the block above every time
}

void TetrisApp::update() {
  try {
    board_.UpdateBoard();
  } catch (std::exception &e) {
    e.what();
  }
}
}  // namespace visualizer

}  // namespace tetris
