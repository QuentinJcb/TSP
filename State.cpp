#include "State.h"
#include "Data.h"
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;

State::State(double radius, int n_cities):data(radius, n_cities) {
	Data data(radius, n_cities);
	this->data = data;
	indices_ = vector<int>();
	indices_.push_back(0);
	indices_.push_back(0);
	schedule_ = vector<int>();
	for (int i=0;i<n_cities;i++) {
		schedule_.push_back(i);
	}
}

double State::getRadius() const{
	return data.getRadius();
}

int State::getNcities() const{
	return data.getNcities();
}

vector<vector<double> > State::getTabCities() const{
	return data.getTabCities();
}

Data State::getData() const{
	return data;
}

vector<int> State::getSchedule() const {
	return schedule_;
}

void State::generateNeighbor() {
	int n_cities = data.getNcities();
	int i = rand() % n_cities;
	int j = rand() % n_cities;
	while(j == i) {
		j = rand() % n_cities;
	}
	indices_[0] = i;
	indices_[1] = j;
	int temp = schedule_[i];
	schedule_[i] = schedule_[j];
	schedule_[j] = temp;

}

void State::comeBack() {
	int i = indices_[0];
	int j = indices_[1];
	int temp = schedule_[i];
	schedule_[i] = schedule_[j];
	schedule_[j] = temp;
}

double State::evalDistance() const {
	int n_cities = data.getNcities();
	vector<int> schedule = schedule_;
	vector<vector<double> > tab_cities = data.getTabCities();
	double distance = 0.0;
	for (int i=0; i < n_cities - 1; i++) {
		distance += sqrt( pow(tab_cities[schedule[i+1]][0] - tab_cities[schedule[i]][0], 2) 
			+  pow(tab_cities[schedule[i+1]][1] - tab_cities[schedule[i]][1], 2));
	}
	distance += sqrt( pow(tab_cities[schedule[n_cities-1]][0] - tab_cities[schedule[0]][0], 2) 
			+  pow(tab_cities[schedule[n_cities-1]][1] - tab_cities[schedule[0]][1], 2));

	return distance;
}

void State::display() const {
	vector<int> schedule = schedule_;
	Data data = this->data;
	vector<vector<double> > tab_cities = data.getTabCities();
	for (vector<int>::iterator it = schedule.begin() ; it != schedule.end(); ++it) {
		double x = tab_cities[*it][0];
		double y = tab_cities[*it][1];
		cout << x << "  " << y << endl;
	}
}