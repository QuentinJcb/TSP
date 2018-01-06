#include "Data.h"
#include "State.h"
#include "SimuAnnealing.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {

	SimuAnnealing annealing(1000, 0.995, true);
	cout << "Heating..." << endl;
	double init_temp = annealing.heatUpLoop(100.0, 25);
	State state(100.0, 25);
	cout << "Initial schedule: " << endl;
	state.display();
	cout << "Cooling..." << endl;
	vector<double> values = annealing.coolingLoop(init_temp, state);
	cout << "Optimized schedule: " << endl;
	state.display();
}