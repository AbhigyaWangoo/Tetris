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

  SECTION("No blocks generated if there are already 3") {
    user_board.GenerateUserBlocks();
    user_board.GenerateUserBlocks();

    passing_condition = user_board.getUserBlocks().size() == 3;
    REQUIRE(passing_condition);
  }

  SECTION("blocks generated if there aren't 3") {
    tetris::Board board;
    glm::vec2 coordinate = glm::vec2(141, 141);

    board.UpdateBoard();

    tetris::BlockSet front = board.getUserBoard().getUserBlocks().front();
    board.PlaceBlock(front, coordinate, 66);

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

  board.UpdateBoard();

  SECTION("Placing block properly in spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate, 66);

    passing_condition = board.getBoard()[0][0] &&
                        board.getBoard()[block.getBlockShape().x - 1][0] &&
                        board.getBoard()[0][block.getBlockShape().y - 1];
    REQUIRE(passing_condition);
  }

  SECTION("Placing 2 adjacent blocks properly in spot") {
    tetris::BlockSet new_block;

    block = board.getUserBoard().getUserBlocks().front();
    new_block = board.getUserBoard().getUserBlocks().back();

    ci::vec2 coordinate = ci::vec2(141, 141);
    ci::vec2 new_coordinate = ci::vec2(141 + block.getBlockShape().y * 66, 207 + block.getBlockShape().x * 66);

    board.PlaceBlock(block, coordinate, 66);
    board.PlaceBlock(new_block, new_coordinate, 66);

    passing_condition = board.getBoard()[0][0] &&
                        board.getBoard()[0][block.getBlockShape().x - 1] &&
                        board.getBoard()[block.getBlockShape().y - 1][0]; // todo you haven't accounted for the other blocks placement

    REQUIRE(passing_condition);
  }

  SECTION("Placing blocks properly in overlapped spot") {
    block = board.getUserBoard().getUserBlocks().front();
    tetris::BlockSet new_block = board.getUserBoard().getUserBlocks().front();

    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate, 66);

    REQUIRE_THROWS_AS(board.PlaceBlock(new_block, coordinate, 66),
                      std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds negative spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(-tetris::kBoardSize * 66, 141);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate, 66), std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds positive spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2((tetris::kBoardSize + 1) * 66, 0);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate, 66), std::runtime_error);
  }

  SECTION("Placing a block removes it from the user_blocks_") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate, 66);

    passing_condition = !(board.getUserBoard().getUserBlocks().front() == block);
    REQUIRE(passing_condition);
  }
}

TEST_CASE("User Clicking") {
  SECTION("User clicks out of grid bounds") {

  }

  SECTION("User clicks out of user block bounds") {

  }

  SECTION("User clicks out of bounds after selecting block") {

  }

  SECTION("User clicks in grid without selecting a block") {

  }
}