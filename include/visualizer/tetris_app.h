#pragma once

#include "../../../../include/glm/vec2.hpp"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "tetris_canvas.h"

namespace tetris {
    namespace visualizer {
        const static double kWindowWidth = 600;
        const static double kWindowLength = 678;
        const ci::vec2 kTopLeft = ci::vec2(tetris::visualizer::kWindowWidth / 6,
                                                  tetris::visualizer::kWindowWidth / 6);
        const ci::vec2 kBottomRight = ci::vec2(tetris::visualizer::kWindowWidth * 5 / 6,
                                     tetris::visualizer::kWindowWidth * 5 / 6);
        static size_t increment_ = (kBottomRight.x - kTopLeft.x) / kBoardSize;
        
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
            
        private:
         tetris::Board board_;
         tetris::visualizer::BoardCanvas canvas_;
        };

    }  // namespace visualizer

}  // namespace tetris
