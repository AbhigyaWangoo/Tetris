//
// Created by Abhigya Wangoo on 11/2/20.
//

#include "core/block.h"

#include <catch2/catch.hpp>

#include "core/board.h"

TEST_CASE("Block initializations") {
  tetris::Board board;
  
  SECTION("Blocks are generated correctly") {
    board.GenerateUserBlocks();
    
    //REQUIRE();
  }
}