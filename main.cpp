#include <iostream>
#include <fstream>
#include "neuron.cpp"
using namespace std;

int main(){

	Neuron n1;
	double simtime;
	double t_start(0.0);
	double t_stop(1000.0);
	double i_start(100);		//which values
	double i_stop(400);
	double I_ext(2.0);
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

			n1.update(simtime, I_ext);
			file<<n1.getPot()<<endl;
			cout<<n1.getPot()<<endl;
			simtime+=n1.getH();

		}

		cout<<"number of spikes: "<<n1.getSpikes()<<endl;
		file.close();

	return 0;
}
