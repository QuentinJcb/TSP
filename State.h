#ifndef STATE_H
#define STATE_H

#include <vector>
#include "Data.h"


class State {

protected:
	std::vector<int> indices_;
	std::vector <int> schedule_;
	Data data;

public:
	State(double radius, int n_cities);
	double getRadius() const;
	int getNcities() const;
	Data getData() const;
	std::vector<std::vector<double> > getTabCities() const;
	std::vector<int> getSchedule() const;
	void generateNeighbor();
	void comeBack();
	double evalDistance() const;
	void display() const;

};

#endif