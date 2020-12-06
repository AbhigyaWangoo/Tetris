//
// Created by Abhigya Wangoo on 10/31/20.
//

#ifndef IDEAL_GAS_PARTICLE_H
#define IDEAL_GAS_PARTICLE_H

#include <cstddef>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <string>

#include "../../../../include/glm/vec2.hpp"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace tetris {
/**
 * Representation of a block
 */
const int kBoardSize = 6;
const int kUserBlockCount = 3;

class BlockSet {
 public:
  /**
   * Finds the shape of the block
   *
   * @return what shape the block is in
   */
  const ci::vec2& getBlockShape() const;

  /**
   * Initializes the block according to the Board's size
   */
  void InitializeBlock();

  /**
   * Determines whether the block is in square shape or an L-shape
   *
   * @return boolean for whichever style the block is in
   */
  bool isSquare() const;

  /**
   * Finds the top left coordinate of the block set
   *
   * @return the top left coordinate
   */
  const glm::vec2& getBlockSetTopLeft() const;

  /**
   * Sets the top left coordinate of the block
   *
   * @param blockSetTopLeft to set
   */
  void setBlockSetTopLeft(const ci::vec2& blockSetTopLeft);

  /**
   * Overloaded operator to check for a block set existing within the user_board_
   *
   * @param rhs block set to compare with lhs
   * @param lhs block set to compare with rhs
   * @return whether the two are equal or not
   */
  friend bool operator==(const BlockSet& rhs, const BlockSet& lhs);

 private:
  ci::vec2 block_shape_ = ci::vec2(0,0);
  ci::vec2 block_set_top_left;
  bool is_square_;
};

}  // namespace tetris

#endif
