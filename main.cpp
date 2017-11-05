#include <iostream>
#include "experiment.h"
using namespace std;


int main(){

	const double t_start(0.0);
	const double t_stop(1000.0);
	Experiment trial;
	trial.setTime(t_start, t_stop);
	trial.simulation();

	return 0;

}
