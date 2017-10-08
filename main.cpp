#include <iostream>
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
	
	cout<<"Enter an external current:"<<endl;
	cin>>I;
	cout<<"And a simulation time:"<<endl;
	cin>>t_stop;
	
	simtime=t_start;
	
	while (simtime<t_stop){
		if (){			//if (neuron is refractory??)
		n1.setV(0.0);
		}	
		else if (n1.getV()>V_thr){
			n1.count_spikes(simtime);	
		}
		n1.update(I);
		simtime+=h;
		}
								
	
	return 0;
}
