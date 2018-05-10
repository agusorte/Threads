#include "robot.h"
#include <iostream>
#include <cstdlib>

Robot::Robot():mrunning(true) {}

Robot::Robot(int i, int j, char id, char (&map)[7][7]):mrunning(true){

	row = i;
	col = j;
	mId = id;
	//map in our robot 
	mMap = new char (49);
	mMap= &map[0][0];


}
// just if we want to stop our robot
void Robot::stop(){
	mrunning = false;
}

void Robot::move(){
	// the motion will be random
	// we will have 4 option
	// up left, right down
	//then we generate random number 0-3
	int opt = rand()%4;
	int row_aux,col_aux;


    // save previous values
	row_aux = row;
	col_aux = col;

    // it dpends of the option we move
	switch(opt){
		case 0:
		// up
		if(row>0 && row <7)
			row--;
		break;
		case 1:
		//left
		if(col>0 && col <7)
			col--;

		break;
		case 2:
		// right
		if(col>=0 && col <6)
			col++;
		break;
		case 3:
		//down
		if(row>=0 && row <6)
			row++;
		break;

	}
	// lock map
	mutexMap.lock();

    // verify empty space
	if(*(mMap+7*row+col) == '0'){
       *(mMap+7*row+col) = mId; // move robot there
       *(mMap+7*row_aux+col_aux) ='0'; // leave the space
	}
	else{ // if no empty space no move maintaint the same position
		row= row_aux;
	    col = col_aux;

	}

	mutexMap.unlock(); // unlocking resource

}

void Robot::run()
{
	while(mrunning){
		move();
        // one second per robot
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

// just for testing not used
void Robot::display()
{


}
