//
// Created by Abhigya Wangoo on 10/31/20.
//

#ifndef IDEAL_GAS_IDEAL_GAS_CANVAS_H
#define IDEAL_GAS_IDEAL_GAS_CANVAS_H

#include <core/block.h>
#include <vector>

#include "../core/board.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace tetris {
    namespace visualizer {
        /**
         * The visualizer for the ideal gas simulation
         */
        class BoardCanvas {
         public:
          /**
           * Renders Current board with highlighted tiles 
           */
          void RenderBoard();
          
          /**
           * Renders all current blocks available to the user
           */
          void RenderUserBlocks();
         private:
          tetris::Board board_;

          /**
           * Renders an individual block
           *  
           * @param increment specifies the square widths
           * @param top_left coordinate to place the rendering
           * @param bottom_right coordinate to place the rendering 
           */
          void RenderBlocks(size_t increment, ci::vec2 top_left);
          
          /**
           * Renders the grid for the player to play the game on
           * 
           * @param top_left coordinate to place the rendering
           * @param bottom_right coordinate to place the rendering
           * @param increment to verify the amount of boxes in the grid
           */
          void RenderGrid(size_t increment, ci::vec2 top_left, ci::vec2 bottom_right);
        };
    }
}

#endif //IDEAL_GAS_IDEAL_GAS_CANVAS_H
