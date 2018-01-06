#ifndef DATA_H
#define DATA_H

#include <vector>
using namespace std;


class Data {

protected:
	double radius_;
	int n_cities_;
	vector<vector<double> > tab_cities_;

public:
	Data(double radius, int n_cities);
	double getRadius() const;
	int getNcities() const;
	vector<vector<double> > getTabCities() const;

};

#endif