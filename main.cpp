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
	const double D(1.5); //delay
	ofstream file;
	simtime=t_start;

	bool spike; //=n1.update()

	file.open("potential.txt");

	if(file.fail()){
		cerr<<"Error when opening the file"<<endl;
	}	else{

		double I;
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

		if(spike==true){										//If n1 spikes, update of n2 at simtime+D
			//n2.update(simtime+D,I_ext); // update before the if???
			n2.setV(n2.getPot()+n1.getJ()); //n2 responds at t=tpre+D V+=J
			n2.update(simtime+D,I_ext);
			cout<<"neuron 2: "<<n2.getPot()<<endl;
			}
			simtime+=n1.getH();
		}

		cout<<"number of spikes: "<<n1.getSpikes()<<endl;
	}
		file.close();

	return 0;
}
