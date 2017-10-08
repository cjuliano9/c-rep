#include <iostream>
#include <fstream>
#include "neuron.cpp"
using namespace std;

int main(){
	
	Neuron n1;
	double simtime;
	double t_start(0.0);
	double t_stop; 
	double h(0.1);
	double I;
	double V_thr(20.0);
	ofstream file;
	
	cout<<"Enter an external current:"<<endl;
	cin>>I;
	cout<<"And a simulation time:"<<endl;
	cin>>t_stop;
	
	simtime=t_start;
	
	file.open("potential.txt");
	
	while (simtime<t_stop){
		
		if (...){			//if (neuron is refractory?-> bool?)
		n1.setV(0.0);		//Vreset / tau_ref
		}
			
		else if (n1.getPot()>V_thr){
			n1.count_spikes(simtime);	//Then set neuron to refractory
		}
		
		n1.update(I);
		file<<n1.getPot();	// register from getter??
		simtime+=h;
	}
		
	file.close();
								
	return 0;
}
