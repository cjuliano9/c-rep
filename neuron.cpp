#include "neuron.h"


bool Neuron::update(int time,int input_current){	
	
			
	if (V>V_thr){
		count_spikes(time);	
		}
	
	if (refractory_count>0.0){			
		V=V_reset;
		refractory_count--;		
		return true;
		}	
		
	else{									
	V=c1*V+c2*input_current;
	return false;
	}
	
}

void Neuron::count_spikes(double t){
	nb_spikes+=1;
	tab_spikes.push_back(t);
}

double Neuron::getPot() const{
	return V;
}

int Neuron::getSpikes() const{
	return nb_spikes;
}

vector<double> Neuron::getTime() const{
	return tab_spikes;
}

 double Neuron::getH() const{
	 return h;
 }

void Neuron::setV(double v){
	V=v;
}


