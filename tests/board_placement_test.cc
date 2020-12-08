//
// Created by Abhigya Wangoo on 11/1/20.
//
#define CATCH_CONFIG_MAIN

#include <visualizer/canvas.h>

#include <catch2/catch.hpp>

#include "core/board.h"

TEST_CASE("Mouse clicks handled correctly") {
  tetris::visualizer::BoardCanvas canvas;
  tetris::Board board;

  SECTION("Selecting a block from user's board") {
    SECTION("Blocks are properly selected based on user clicks") {

      REQUIRE(true);
    }
  }
}