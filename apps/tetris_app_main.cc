#include <visualizer/tetris_app.h>

using tetris::visualizer::TetrisApp;

void prepareSettings(TetrisApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(TetrisApp, ci::app::RendererGl, prepareSettings);