#include "neuron.hpp"
#include <random>

Neuron::Neuron():V(-70),V_thres(-55),input_current(0),nb_spikes(0),tab_spikes(0),h(0.1),tau(20),tau_ref(2), R(3),c1(exp(-h/tau)),c2(R*(1-c1))
{}

void Neuron::update(int n){
	for(int i(0);i<n;++i){						
			nb_spikes+=1;							
			tab_spikes.push_back();		//??					
		  	V=c1*V+c2*input_current;
	}
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



void Neuron::initialize_current(){
		auto input_current= uniform(0,400);
}
