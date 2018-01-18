#ifndef SIMU_ANNEALING_H
#define SIMU_ANNEALING_H
#include<vector>
#include "State.h"


class SimuAnnealing {

public:
	SimuAnnealing(int nb_transitions, double alpha, bool is_minimisation);
	bool accept(const double& yi, const double& yj, const double& temperature) const;
	double heatUpLoop(double radius, int n_cities);
	std::vector<double> coolingLoop(const double& init_temp, State& state);

protected:
	int nb_transitions_;
	double alpha_;
	bool is_minimisation_;

};
#endif
