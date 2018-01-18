#ifndef DATA_H
#define DATA_H

#include <vector>


class Data {

protected:
	double radius_;
	int n_cities_;
	std::vector<std::vector<double> > tab_cities_;

public:
	Data(double radius, int n_cities);
	double getRadius() const;
	int getNcities() const;
	std::vector<std::vector<double> > getTabCities() const;

};

#endif