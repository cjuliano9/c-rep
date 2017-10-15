#include <iostream>
#include <fstream>
#include "neuron.cpp"
using namespace std;

int main(){

	Neuron n1;
	Neuron n2;

	double simtime;
	const double t_start(0.0);
	const double t_stop(1000.0);
	const double i_start(100);		//which values
	const double i_stop(400);
	const double I_ext(2.0);

	ofstream file;
	simtime=t_start;
	double I;
	bool spike; //=n1.update()

	file.open("potential.txt");

	if(file.fail()){
		cerr<<"Error when opening the file"<<endl;
	}	else{

		while (simtime<t_stop){

			if (simtime<i_start or simtime>i_stop){
			I=0.0;
			}

			else{
			I=I_ext;
			}

			spike=n1.update(simtime, I_ext);
			file<<n1.getPot()<<endl;
			cout<<"neuron 1: "<<n1.getPot()<<endl;

			if(spike==true){										//If n1 spikes at t=simtime, update of n2 at t+D
			n2.setDelay();
			}
			n2.update(simtime,I_ext);

			cout<<"neuron 2: "<<n2.getPot()<<endl;
			simtime+=n1.getH();
		}

		cout<<"number of spikes: "<<n1.getSpikes()<<endl;
	}
		file.close();

	return 0;
}
