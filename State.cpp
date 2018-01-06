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
	this->indices_ = vector<int>();
	this->indices_.push_back(0);
	this->indices_.push_back(0);
	this->schedule_ = vector<int>();
	for (int i=0;i<n_cities;i++) {
		this->schedule_.push_back(i);
	}
}

double State::getRadius() const{
	return this->data.getRadius();
}

int State::getNcities() const{
	return this->data.getNcities();
}

vector<vector<double> > State::getTabCities() const{
	return this->data.getTabCities();
}

Data State::getData() const{
	return this->data;
}

vector<int> State::getSchedule() const {
	return this->schedule_;
}

void State::generateNeighbor() {
	int n_cities = this->data.getNcities();
	int i = rand() % n_cities;
	int j = rand() % n_cities;
	while(j == i) {
		j = rand() % n_cities;
	}
	this->indices_[0] = i;
	this->indices_[1] = j;
	int temp = this->schedule_[i];
	this->schedule_[i] = this->schedule_[j];
	this->schedule_[j] = temp;

}

void State::comeBack() {
	int i = this->indices_[0];
	int j = this->indices_[1];
	int temp = this->schedule_[i];
	this->schedule_[i] = this->schedule_[j];
	this->schedule_[j] = temp;
}

double State::evalDistance() {
	int n_cities = this->data.getNcities();
	vector<int> schedule = this->schedule_;
	vector<vector<double> > tab_cities = this->data.getTabCities();
	double distance = 0.0;
	for (int i=0; i < n_cities - 1; i++) {
		distance += sqrt( pow(tab_cities[schedule[i+1]][0] - tab_cities[schedule[i]][0], 2) 
			+  pow(tab_cities[schedule[i+1]][1] - tab_cities[schedule[i]][1], 2));
	}
	distance += sqrt( pow(tab_cities[schedule[n_cities-1]][0] - tab_cities[schedule[0]][0], 2) 
			+  pow(tab_cities[schedule[n_cities-1]][1] - tab_cities[schedule[0]][1], 2));

	return distance;
}

void State::display() {
	vector<int> schedule = this->schedule_;
	Data data = this->data;
	vector<vector<double> > tab_cities = this->data.getTabCities();
	for (vector<int>::iterator it = schedule.begin() ; it != schedule.end(); ++it) {
		double x = tab_cities[*it][0];
		double y = tab_cities[*it][1];
		cout << x << "  " << y << endl;
	}
}