#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <iomanip>
using namespace std;

class Leaderboard {
private:
	unsigned int mazeNumber;
	string mazeName;
	bool emptyBoard;
public:
	Leaderboard(unsigned int mazeNumber);//Class constructor (makes sure file exists)
	void addWinner(string name, double time);
	void print();
};
#endif
