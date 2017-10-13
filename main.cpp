#include <iostream>
#include <fstream>
#include "neuron.cpp"
using namespace std;

int main(){

	Neuron n1;
	double simtime;
	double t_start(0.0);
	double t_stop(1000.0);
	double i_start(100);
	double i_stop(400);
	double I_ext(1.01);
	ofstream file;
	simtime=t_start;

	/*
	bool isRefractory;*/

	file.open("potential.txt");

		double I;

		while (simtime<t_stop){

			if (simtime<i_start or simtime>i_stop){
			I=0.0;
			}

			else{
			I=I_ext;
			}

			n1.update(simtime, I);
			file<<n1.getPot()<<endl;
			simtime+=n1.getH();

		}


	file.close();

	return 0;
}
