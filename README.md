# "Drag" Tetris 
  
  This is a cinder framework implementation of the game, tetris. Although the game is not a play-by-play of the original game, users can still place blocks to clear rows. 
  
  In this implementation, users will be given a 6 x 6 board with three "block sets" at the bottom of the board. Players will be able to click on a block, then click on the top left tile on the board they want to place the block on. Doing so will place that block on the board and replace the previous block with a new one.
  
  For instance, if one of the blocks is a 2 x 2 square, and I place the block on the top left of the board, by clicking on the block and then on the top left of the board, a block will be placed on the top left of the board. Full rows and columns will be cleared and the number of rows and columns cleared will be allocated as points to the player.
  
  The objective of the game is to place as many blocks as possible without filling up the board with no filled rows or columns.
  
  
  **SETUP INSTRUCTIONS**
  
  In order to setup the game, first you need a fully compiled Cinder project. Then, create a folder within the root directory called my-projects, enter the folder, and git clone this repository.
