//
// Created by Abhigya Wangoo on 11/2/20.
//

#include <catch2/catch.hpp>

#include "core/block_set.h"
#include "core/board.h"

TEST_CASE("BlockSet initializations") {
  tetris::Board board;
  bool passing_condition = false;
  
  SECTION("Blocks are generated correctly") {
    board.GenerateUserBlocks();
    
    passing_condition = board.getUserBlocks().size() == 3;
    REQUIRE(passing_condition); 
  }
}

TEST_CASE("Placing blocks") {
  tetris::Board board;
  tetris::BlockSet block;
  bool passing_condition = false;
  
  SECTION("Placing blocks properly in spot") {
    board.GenerateUserBlocks();
    block = board.getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(0,0);
    
    board.PlaceBlock(block, coordinate);
    
    passing_condition = board.getBoard().size() == 1 && board.getBoard()[0][0];
    REQUIRE(passing_condition);
  }

  SECTION("Placing blocks properly in overlapped spot") {
    board.GenerateUserBlocks();
    block = board.getUserBlocks().front();
    tetris::BlockSet new_block = board.getUserBlocks().back();;
    
    ci::vec2 coordinate = ci::vec2(0,0);
    
    
    board.PlaceBlock(block, coordinate);
    
    REQUIRE_THROWS_AS(board.PlaceBlock(new_block, coordinate), std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds spot") {
    board.GenerateUserBlocks();
    block = board.getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(0,0);

    board.PlaceBlock(block, coordinate);

    passing_condition = board.getBoard().size() == 1 && board.getBoard()[0][0];
    REQUIRE(passing_condition);
  }
}