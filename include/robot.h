#ifndef ROBOT_H_
#define ROBOT_H_

#include "world.h"
#include <mutex>

// Forward declaration
class World;

// Define and implement the following class
class Robot {
 public:
  Robot();
  //recharged function
  Robot(int i, int j, char id, char (&map)[7][7]);

  // principal function thread
  // for each robot
  void run();
  // stop moving robot just in case 
  // something bad is going on
  void stop();

  //move robot for a free space
  // we will do random move
  //up left right down
  // very simple
  void move();

// not used
  void display();


 private:
	// current position
	int row,col;
	// id
	char mId; 
	//variable just to stop the thread
	bool mrunning;

	// we need too for make independt 
	// every robot
	char *mMap;

    // mutex for  lock the shared
    //resource map
	std::mutex mutexMap;

};

#endif
