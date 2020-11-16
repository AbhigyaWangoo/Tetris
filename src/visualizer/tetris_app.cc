#include <visualizer/tetris_app.h>

namespace tetris {
    namespace visualizer {
        void TetrisApp::draw() {
            ci::Color8u background_color(0, 0, 0);
            ci::gl::clear(background_color);
            setWindowSize(kWindowSize, kWindowSize);


            ci::gl::drawStringCentered(
                    "Tetris",
                    glm::vec2(kWindowSize / 2, kWindowSize / 10), ci::Color("white"));
        }

        void TetrisApp::setup() {
        }

        void TetrisApp::update() {
        }
    }  // namespace visualizer

}  // namespace naivebayes
