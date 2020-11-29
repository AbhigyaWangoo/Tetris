//
// Created by Abhigya Wangoo on 11/2/20.
//

#include <core/user_board.h>

#include <catch2/catch.hpp>

#include "core/block_set.h"
#include "core/board.h"

TEST_CASE("BlockSet initializations") {
  tetris::UserBoard user_board;
  bool passing_condition;

  SECTION("Blocks are generated correctly") {
    user_board.GenerateUserBlocks();

    passing_condition = user_board.getUserBlocks().size() == 3;
    REQUIRE(passing_condition);
  }
}

TEST_CASE("Placing blocks") {
  tetris::Board board;
  tetris::BlockSet block;
  tetris::UserBoard user_board;
  bool passing_condition = false;

  SECTION("Placing block properly in spot") {
    user_board.GenerateUserBlocks();
    block = user_board.getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(0, 0);

    board.PlaceBlock(block, coordinate);

    passing_condition = board.getBoard()[0][0] &&
                        board.getBoard()[block.getBlockShape().x][0] &&
                        board.getBoard()[0][block.getBlockShape().y];
    REQUIRE(passing_condition);
  }

  SECTION("Placing 2 adjacent blocks properly in spot") {
    tetris::BlockSet new_block;

    block.InitializeBlock(false);
    new_block.InitializeBlock(false);
    
    ci::vec2 coordinate = ci::vec2(0, 0);
    ci::vec2 new_coordinate = ci::vec2(block.getBlockShape().x + 1, 0);

    board.PlaceBlock(block, coordinate);
    board.PlaceBlock(new_block, new_coordinate);

    passing_condition = board.getBoard()[0][0] &&
                        board.getBoard()[block.getBlockShape().x][0] &&
                        board.getBoard()[0][block.getBlockShape().y] &&
                        board.getBoard()[block.getBlockShape().x + 1][0];
    
    REQUIRE(passing_condition);
  }

  SECTION("Placing blocks properly in overlapped spot") {
    user_board.GenerateUserBlocks();
    block = user_board.getUserBlocks().front();
    tetris::BlockSet new_block = user_board.getUserBlocks().back();
    ;

    ci::vec2 coordinate = ci::vec2(0, 0);

    board.PlaceBlock(block, coordinate);

    REQUIRE_THROWS_AS(board.PlaceBlock(new_block, coordinate),
                      std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds negative spot") {
    user_board.GenerateUserBlocks();
    block = user_board.getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(-tetris::kBoardSize, 0);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate), std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds positive spot") {
    user_board.GenerateUserBlocks();
    block = user_board.getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(tetris::kBoardSize + 1, 0);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate), std::runtime_error);
  }
}