#include "neuron.h"


void Neuron::update(int input_current){										
	V=c1*V+c2*input_current;
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

void Neuron::setV(double v){
	V=v;
}


