//
// Created by Abhigya Wangoo on 11/2/20.
//

#include <core/user_board.h>

#include <catch2/catch.hpp>

#include "core/block_set.h"
#include "core/board.h"
#include "visualizer/canvas.h"

size_t increment = 66;

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
    board.PlaceBlock(front, coordinate, increment);

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

TEST_CASE("Placing blocks") {
  tetris::Board board;
  tetris::BlockSet block;
  bool passing_condition;

  board.UpdateBoard();

  SECTION("Placing block properly in spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate, increment);

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
    ci::vec2 new_coordinate =
        ci::vec2(141 + block.getBlockShape().y * increment,
                 207 + block.getBlockShape().x * increment);

    board.PlaceBlock(block, coordinate, increment);
    board.PlaceBlock(new_block, new_coordinate, increment);

    passing_condition = board.getBoard()[0][0] &&
                        board.getBoard()[0][block.getBlockShape().x - 1] &&
                        board.getBoard()[block.getBlockShape().y - 1]
                                        [0];  // todo you haven't accounted for
                                              // the other blocks placement

    REQUIRE(passing_condition);
  }

  SECTION("Placing blocks properly in overlapped spot") {
    block = board.getUserBoard().getUserBlocks().front();
    tetris::BlockSet new_block = board.getUserBoard().getUserBlocks().front();

    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate, increment);

    REQUIRE_THROWS_AS(board.PlaceBlock(new_block, coordinate, increment),
                      std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds negative spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(-tetris::kBoardSize * increment, 141);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate, increment),
                      std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds positive spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2((tetris::kBoardSize + 1) * increment, 0);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate, increment),
                      std::runtime_error);
  }

  SECTION("Placing a block removes it from the user_blocks_") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate, increment);

    passing_condition = !(board.getUserBoard().getUserBlocks().front() == block);
    REQUIRE(passing_condition);
  }
}

TEST_CASE("User Clicking") {
  tetris::visualizer::BoardCanvas canvas;
  tetris::Board board;
  ci::vec2 coordinate = ci::vec2(-1, 0);

  board.UpdateBoard();

  SECTION("User clicks out of grid bounds") {
    canvas = tetris::visualizer::BoardCanvas(board);

    REQUIRE_THROWS_AS(canvas.SelectBlock(coordinate), std::runtime_error);
  }

  SECTION("User clicks out of user block bounds") {
    canvas = tetris::visualizer::BoardCanvas(board);
    coordinate = ci::vec2(1 * increment, 2 * increment);

    REQUIRE_THROWS_AS(canvas.SelectBlock(coordinate), std::runtime_error);
  }

  SECTION("User clicks out of bounds after selecting block") {
    ci::vec2 user_blocks_top_left = ci::vec2(100, 500);
    ci::vec2 user_blocks_bottom_right = ci::vec2(400, 700);

    board.setUserBoardCoordinates(user_blocks_top_left,
                                  user_blocks_bottom_right);
    canvas = tetris::visualizer::BoardCanvas(board);
    coordinate =
        ci::vec2(user_blocks_top_left.x + 50, user_blocks_top_left.y + 50);

    canvas.SelectBlock(coordinate);
    coordinate = ci::vec2(-1, -1);

    REQUIRE_THROWS_AS(board.PlaceBlock(const_cast<tetris::BlockSet&>(
                                           canvas.getCurrentBlock()),
                                       coordinate, increment),
                      std::runtime_error);
  }

  SECTION("User clicks in grid without selecting a block") {
    REQUIRE_THROWS_AS(board.PlaceBlock(const_cast<tetris::BlockSet&>(
                                           canvas.getCurrentBlock()),
                                       coordinate, increment),
                      std::runtime_error);
  }
}

TEST_CASE("Tracking scoring") {
  tetris::visualizer::BoardCanvas canvas;
  tetris::Board board;
  tetris::BlockSet three_by_three;

  SECTION("Clearing a row/column increases the score by one") {
    ci::vec2 first_position = ci::vec2(141,555);
    board.UpdateBoard();

    canvas = tetris::visualizer::BoardCanvas(board);

    canvas.SelectBlock(first_position);
//    board.PlaceBlock(canvas.getCurrentBlock(),)

    REQUIRE(true);
  }

  SECTION("Clearing multiple rows/columns increases the score by the amount cleared") {
    // TODO
    REQUIRE(true);
  }
}