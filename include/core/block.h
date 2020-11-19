//
// Created by Abhigya Wangoo on 10/31/20.
//

#ifndef IDEAL_GAS_PARTICLE_H
#define IDEAL_GAS_PARTICLE_H

#include <glm/glm.hpp>
#include <string>

#include "../../../../include/glm/vec2.hpp"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace tetris {
/**
 * Representation of a particle
 */
const int kBoardSize = 6;
const int kUserBlockCount = 3;
class Block {
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
   * 
   * @param is_square to specify whether it's angled or a square shape 
   */
  void InitializeBlock(bool is_square);
 private:
  ci::vec2 block_shape_;
  ci::vec2 block_coordinate_;
  bool is_square_;
};

}  // namespace tetris

#endif
