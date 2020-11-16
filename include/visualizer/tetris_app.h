#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace tetris {
    namespace visualizer {
        const double kWindowSize = 600;
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
        };

    }  // namespace visualizer

}  // namespace tetris
