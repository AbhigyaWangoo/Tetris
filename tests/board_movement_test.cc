//
// Created by Abhigya Wangoo on 11/1/20.
//
#define CATCH_CONFIG_MAIN

#include <visualizer/canvas.h>

#include <catch2/catch.hpp>

#include "core/board.h"

TEST_CASE("Placing blocks") {
  tetris::Board board;
  tetris::BlockSet block;
  bool passing_condition;

  board.UpdateBoard();

  SECTION("Placing block properly in spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate);

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
        ci::vec2(141 + block.getBlockShape().y,400 + block.getBlockShape().x );

    board.PlaceBlock(block, coordinate);
    board.PlaceBlock(new_block, new_coordinate);

    passing_condition = board.getBoard()[0][0] &&
                        board.getBoard()[0][block.getBlockShape().x - 1] &&
                        board.getBoard()[block.getBlockShape().y - 1]
                        [0];

    REQUIRE(passing_condition);
  }

  SECTION("Placing blocks properly in overlapped spot") {
    block = board.getUserBoard().getUserBlocks().front();
    tetris::BlockSet new_block = board.getUserBoard().getUserBlocks().front();

    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate);

    REQUIRE_THROWS_AS(board.PlaceBlock(new_block, coordinate),
                      std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds negative spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(-tetris::kBoardSize * tetris::kIncrement, 141);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate),
                      std::runtime_error);
  }

  SECTION("Placing blocks properly in out of bounds positive spot") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2((tetris::kBoardSize + 1) * tetris::kIncrement, 0);

    REQUIRE_THROWS_AS(board.PlaceBlock(block, coordinate),
                      std::runtime_error);
  }

  SECTION("Placing a block removes it from the user_blocks_") {
    block = board.getUserBoard().getUserBlocks().front();
    ci::vec2 coordinate = ci::vec2(141, 141);

    board.PlaceBlock(block, coordinate);

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
    coordinate = ci::vec2(1 * tetris::kIncrement, 2 * tetris::kIncrement);

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
                                       coordinate),
                      std::runtime_error);
  }

  SECTION("User clicks in grid without selecting a block") {
    REQUIRE_THROWS_AS(board.PlaceBlock(const_cast<tetris::BlockSet&>(
                                           canvas.getCurrentBlock()),
                                       coordinate),
                      std::runtime_error);
  }
}

TEST_CASE("Tracking scoring") {
  tetris::visualizer::BoardCanvas canvas;
  tetris::Board board;
  tetris::BlockSet three_by_three;
  bool passing_condition;

  SECTION("Clearing a row/column or set of rows and columns increases the score") {
    ci::vec2 user_blocks_top_left = ci::vec2(67, 533);
    ci::vec2 user_blocks_bottom_right = ci::vec2(533, 967);
    ci::vec2 coordinate;

    board.UpdateBoard();
    board.setUserBoardCoordinates(user_blocks_top_left,
                                  user_blocks_bottom_right);
    canvas = tetris::visualizer::BoardCanvas(board);
    coordinate = ci::vec2(user_blocks_top_left.x + 50, user_blocks_top_left.y + 50);
    canvas.SelectBlock(coordinate);
    tetris::BlockSet current_block = canvas.getCurrentBlock();

    coordinate = ci::vec2(user_blocks_top_left.x + 50, user_blocks_top_left.x+50);
    board.PlaceBlock(current_block, coordinate);

    size_t i = 0;
    size_t j = current_block.getBlockShape().x + 1;

    if (!board.getBoard()[i][j] && j < tetris::kBoardSize) {
      coordinate = ci::vec2(user_blocks_top_left.x + 300, user_blocks_top_left.y + 50);
      canvas.SelectBlock(coordinate);
      current_block = canvas.getCurrentBlock();

      coordinate = ci::vec2(374, 149);
      board.PlaceBlock(current_block, coordinate);
      board.UpdateBoard();
      canvas = tetris::visualizer::BoardCanvas(board);
    }

    passing_condition = board.getPlayerScore() > 0;
    REQUIRE(passing_condition);
  }
}