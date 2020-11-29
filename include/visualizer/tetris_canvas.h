//
// Created by Abhigya Wangoo on 10/31/20.
//

#ifndef IDEAL_GAS_IDEAL_GAS_CANVAS_H
#define IDEAL_GAS_IDEAL_GAS_CANVAS_H

#include <core/block_set.h>

#include <vector>

#include "../core/board.h"
#include "../core/user_board.h"
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
          BoardCanvas();
          
          /**
           * TODO
           * @param board 
           */
          BoardCanvas(tetris::Board &board);
          /**
           * Renders Current board with highlighted tiles 
           */
          void RenderBoard();
          
          /**
           * Renders all current blocks available to the user
           * 
           * @param top_left coordinate of the board so the user blocks are displayed correctly
           * @param bottom_right coordinate of the board so the user blocks are displayed correctly
           */
          void RenderUserBlocks();
          
         private:
          tetris::Board board_;
          tetris::UserBoard user_blocks_;
          
          /**
           * Renders an individual block
           *  
           * @param top_left coordinate to place the pre_rendered_grid
           * @param bottom_right coordinate to place the pre_rendered_grid
           * @param pre_rendered_grid provides the pixel values to render
           */
          void RenderBlocks(ci::vec2 &top_left, ci::vec2 &bottom_right, const std::vector<std::vector<bool>> &pre_rendered_grid);
          
          /**
           * Renders the grid for the player to play the game on
           */
          void RenderGrid();
        };
    }
}

#endif //IDEAL_GAS_IDEAL_GAS_CANVAS_H
