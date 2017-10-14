#include "neuron.h"


bool Neuron::update(int time,int input_current){		//why value 20.037 registered? -> to correct

	if (refractory_count>0.0){
		V=V_reset;
		refractory_count--;
		return true;
	} else{
				if (V>V_thr){
				count_spikes(time);
				V=V_reset;
				refractory_count=(ref_t/h);
				return true;
				}
					else{
						V=c1*V+c2*input_current;   //+J for every neuron or postsynaptic only???
						return false;
						}
			}
}

void Neuron::count_spikes(double t){
	nb_spikes+=1;
	tab_spikes.push_back(t);
}

double Neuron::getJ() const{
	return J;
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
