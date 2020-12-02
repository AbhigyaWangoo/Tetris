#pragma once

#include "../../../../include/glm/vec2.hpp"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "tetris_canvas.h"

namespace tetris {
const static double kWindowWidth = 600;
const static double kWindowLength = 678;
const ci::vec2 kTopLeft = ci::vec2(kWindowWidth / 6,kWindowWidth / 6);
const ci::vec2 kBottomRight = ci::vec2(kWindowWidth * 5 / 6,kWindowWidth * 5 / 6);
static size_t increment_ = (kBottomRight.x - kTopLeft.x) / kBoardSize;

namespace visualizer {

/**
 * Simulates a set of particles bouncing around in a box
 */
class TetrisApp : public ci::app::App {
 public:
  /**
   * Sets up Ideal gas app
   */
  void setup() override;

  /**
   * Core of app, creates gas chamber visualization
   */
  void draw() override;

  /**
   * Updates each frame of the app
   */
  void update() override;

  /**
   * Finds when the user clicks on a block
   * 
   * @param event representing the clicked area 
   */
  void mouseDown(ci::app::MouseEvent event) override;
  
 private:
  tetris::Board board_;
  tetris::visualizer::BoardCanvas canvas_;
  BlockSet current_block_;
  bool has_selected_block_ = false;
};

}  // namespace visualizer

}  // namespace tetris
