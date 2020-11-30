//
// Created by Abhigya Wangoo on 10/31/20.
//

#ifndef IDEAL_GAS_PARTICLE_H
#define IDEAL_GAS_PARTICLE_H

#include <cstddef>
#include <glm/glm.hpp>
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
   * Determines whether the current block can be created
   *
   * @return whether the current block is valid or not
   */
  bool IsValidBlock() const;

  /**
   * Sets the block's square status
   *
   * @param isSquare to assign the block's status
   */
  void setIsSquare(bool isSquare);

  /**
   * Finds the shape of the block
   *
   * @return what shape the block is in
   */
  const ci::vec2& getBlockShape() const;

  /**
   * Gets the coordinate of the block
   *
   * @return the coordinate of the block
   */
  const glm::vec2& getBlockCoordinate() const;

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
   * Sets the block's incremental value to the one provided
   *
   * @param increment to specify the increment size
   */
  void setIncrement(const size_t& increment);

 private:
  ci::vec2 block_shape_;
  ci::vec2 block_top_left_;
  size_t increment;
  bool is_square_;
};

}  // namespace tetris

#endif
