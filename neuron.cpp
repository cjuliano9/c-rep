#include "neuron.h"


bool Neuron::update(int time,double input_current){

	if (refractory_count>0.0){
		V=V_reset;
		refractory_count--;
		return true;
	}

	 else{

		 V=c1*V+c2*input_current;

		 if (delay==true){

		 	if (delay_count>0.0){
	 	 	delay_count--;
	 	 	}

			else{
			V+=J;
			}
		}

		 	if (V>V_thr){
			count_spikes(time);
			V=V_reset;
			refractory_count=(ref_t/h);
			return true;
			}

			else{
				return false;
			}
		}
}


void Neuron::count_spikes(double t){
	nb_spikes+=1;
	tab_spikes.push_back(t);
}

/*double Neuron::getJ() const{
	return J;
}*/

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


void Neuron::setDelay(){
	delay_count=(D/h);
	delay=true;
}
