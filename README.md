# Conway's Game of Life

Conway's Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves.
## Let There Be Life

The game of life works by having a grid of cells, each of which can be either alive or dead. The game progresses in steps, and at each step, the following rules are applied to each cell: 

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## The Implementation

In this implementation we use a "world" that has dimensions of 512x512.  Each of the positions in this world can be occupied by either a live or a dead cell.  Then the simulation is run through a number of timed iterations. For each iteration the entire state of the world is saved as an image, and at the end of the iterations the images are combined into an animated image. 

## Results
![Results](./output.gif)