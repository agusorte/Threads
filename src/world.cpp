#include <iostream>
#include <chrono>
#include "world.h"

World::World(char map[7][7]) {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      map_[i][j] = map[i][j];
    }
  }
}

bool World::addRobot(int row, int col) {
  map_[row][col] = 'A';
  return true;
}

bool World::addRobot(int row, int col, char robotid) {

  // we add a robot in 2 lists
  // one per object robot and one per thread
  // this way any robot can modiry the pathS
  map_[row][col] = robotid;

 // we crate a new robot object in position and id
  Robot * mRobot = new Robot(row,col,robotid,map_);
  // new thread for this robot
  std::thread* mtRobot = new std::thread(&Robot::run,mRobot);
  // we push in 2 vectors
  mRobots.push_back(mRobot);
  mtRobots.push_back(mtRobot);


  return true;
}

void World::run() {

  while (true) {
    display();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void World::display() {
  // "Clear" screen
  for (int i = 0; i < 20; i++)
    std::cout << std::endl;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      std::cout << map_[i][j];
    }
    std::cout << std::endl;
  }
}
