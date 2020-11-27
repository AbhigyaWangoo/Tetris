#include <visualizer/tetris_app.h>

namespace tetris {
    namespace visualizer {
        void TetrisApp::draw() {
            ci::Color8u background_color(0, 0, 0);
            ci::gl::clear(background_color);
            setWindowSize(kWindowWidth, kWindowLength);

            canvas_.RenderBoard();

            ci::gl::drawStringCentered(
                    "Tetris",
                    glm::vec2(kWindowWidth / 2, kWindowLength / 11), ci::Color("white"));
        }

        void TetrisApp::setup() {
        }

        void TetrisApp::update() {
          
        }
        
        void TetrisApp::keyDown(ci::app::KeyEvent event) {
          switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_RETURN:
              BlockSet sample_block;
              sample_block.InitializeBlock(false);
              ci::vec2 sample_position = ci::vec2(1, 1);

              board_.PlaceBlock(sample_block, sample_position);
              
              canvas_ = BoardCanvas(board_);
              canvas_.RenderBoard();
              break;
          }
        }
        }  // namespace visualizer

}  // namespace naivebayes
