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
}

void TetrisApp::update() {
  try {
    board_.UpdateBoard();
  } catch (std::runtime_error &error) {
    std::cout << error.what();
  } catch (std::range_error &error) {
    // TODO IDK DO SOMETHING TO SIGNIFY ENDGAME
  }
}

void TetrisApp::mouseDown(ci::app::MouseEvent event) {
  ci::vec2 position = event.getPos();

  try {
    if (!has_selected_block_) {
      canvas_.SelectBlock(position);
      current_block_ = canvas_.getCurrentBlock();

      has_selected_block_ = true;
    } else {
      board_.PlaceBlock(current_block_, position, increment_);

      has_selected_block_ = false;
    }
  } catch (std::runtime_error &error) {
    std::cout << error.what();
  }
}

}  // namespace visualizer

}  // namespace tetris
