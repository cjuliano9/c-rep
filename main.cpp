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
	const double I_ext(2.0); //external current

	ofstream file;
	simtime=t_start;
	bool spike1; //=n1.update()
	bool spike2;
	double I;

	/*void setCurrent(double I){
			I_ext=I;
	}*/

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

			//for (int i(0);i<tab_neuron.size();++i){ spike=tab_neuron[i].update(simtime,I_ext)}
			spike1=n1.update(simtime, I_ext);
			//spike2=n2.update(simtime,I_ext);
			//pour tout n target
			if (n2.postsynaptic==true){
				n2.update(simtime,0.0);
				if(n2.getPot()==0.0){
					n2.postsynaptic=false;
				}
			}

			file<<n1.getPot()<<endl;
			cout<<"neuron 1: "<<n1.getPot()<<endl;

			//if(spike==true){}						//If n1 spikes at t=simtime, update of n2 at t+D
			n2.connexion(simtime,I_ext,spike1);		//when delay count=0, V+=J

			cout<<"neuron 2: "<<n2.getPot()<<endl;
			simtime+=n1.getH();					//increase global clock
		}

		cout<<"number of spikes: "<<n1.getSpikes()<<endl;
		cout<<"spikes n2: "<<n2.getSpikes()<<endl;
	}
		file.close();

	return 0;
}
