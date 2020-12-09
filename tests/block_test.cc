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

  SECTION("Blocks are generated correctly according to kUserBoardSize") {
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
    board.PlaceBlock(front, coordinate);

    passing_condition = board.getUserBoard().getUserBlocks().size() == 3;
    REQUIRE(passing_condition);
  }

  SECTION("Block lengths are never past half of the board size") {
    tetris::Board board;

    passing_condition = true;
    for (const tetris::BlockSet &block_set: board.getUserBoard().getUserBlocks()) {
      if (block_set.getBlockShape().x > tetris::kBoardSize / 2 || block_set.getBlockShape().x > tetris::kBoardSize / 2 ) {
        passing_condition = false;
        break;
      }
    }

    REQUIRE(passing_condition);
  }
}