#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "robot.h"
#include <mutex>
#include <thread>

// Forward declaration
class Robot;

// Define and implement the following class. Feel free to change the given
// interfaces and data structures to better match your design
class World {
 public:
  World(char map[7][7]);
  bool addRobot(int row, int col);

  bool addRobot(int row, int col, char robotid);

  void run();
  void display();

 private:
  char map_[7][7];

  // our robots
  std::vector<std::thread*> mtRobots;
  std::vector<Robot*> mRobots;



};

#endif
