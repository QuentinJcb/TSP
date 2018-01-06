#include "SimuAnnealing.h"
#include "State.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <random>

using namespace std;

SimuAnnealing::SimuAnnealing(int nb_transitions, double alpha, bool is_minimisation) {
	this->nb_transitions_ = nb_transitions;
	this->alpha_ = alpha;
	this-> is_minimisation_ = is_minimisation;
	cout << "Object Simu is being created" << endl;
}

bool SimuAnnealing::accept(const double& yi, const double& yj, const double& temperature) {
	if (!this->is_minimisation_) {
		if (yj >= yi) {
			return true;
		}
		double proba = exp((yj - yi)/temperature);
		random_device rd;
		mt19937 gen(rd());
		bernoulli_distribution d(proba);
		bool result = d(gen);
		return result;

	}
	else {
		if (yj <= yi) {
			return true;
		}
		double proba = exp(-(yj - yi)/temperature);
		random_device rd;
		mt19937 gen(rd());
		bernoulli_distribution d(proba);
		bool result = d(gen);
		return result;
	}
}

double SimuAnnealing::heatUpLoop(double radius, int n_cities) {
	double target_proba = 0.8;
	double distance = 0.0;
	State state(radius, n_cities);
	for(int i=0; i < this->nb_transitions_; i++) {
		double yi = state.evalDistance();
		state.generateNeighbor();
		double yj = state.evalDistance();
		distance += abs(yj - yi);
	}
	double mean_distance = distance/this->nb_transitions_;
	double temperature = - mean_distance/log(target_proba);
	return temperature;
}

vector<double> SimuAnnealing::coolingLoop(const double& init_temp, State& state) {
	double temperature = init_temp;
	vector<double> values;
	double yi = state.evalDistance();

	while (temperature > 1e-4 * init_temp) {
		for (int i=0;i < this->nb_transitions_; i++) {
			state.generateNeighbor();
			double yj = state.evalDistance();
			if (this->accept(yi, yj, temperature)) {
				yi = yj;
			}
			else {
				state.comeBack();
			}
		}
		temperature *= this->alpha_;
		values.push_back(yi);
	}
	return values;
}

