#ifndef STATE_H
#define STATE_H

#include <vector>
#include "Data.h"

using namespace std;

class State {

protected:
	vector<int> indices_;
	vector <int> schedule_;
	Data data;

public:
	State(double radius, int n_cities);
	double getRadius() const;
	int getNcities() const;
	Data getData() const;
	vector<vector<double> > getTabCities() const;
	vector<int> getSchedule() const;
	void generateNeighbor();
	void comeBack();
	double evalDistance() const;
	void display() const;

};

#endif