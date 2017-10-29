#include "neuron.h"


bool Neuron::update(int time,double input_current){

	if (refractory_count>0.0){
		V=V_reset;
		refractory_count--;
		return false;
	}
	 else{
		 V=c1*V+c2*input_current+buffer[time%(delay_count+1)];
		 buffer[time%(delay_count+1)]=0.0; //remet a zéro
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
		n_clock++;
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

 double Neuron::getD() const{
	 return delay_count;
 }

void Neuron::setV(double v){
	V=v;
}
void Neuron::setJ(double j){
	J=j;
}


int Neuron::getIndex(int i) const{
	return connexion_index[i];
}

size_t Neuron::getSize() const{
	return connexion_index.size();
}

void Neuron::setIndex(int j){
	connexion_index.push_back(j);
}

void Neuron::receive(int time){		//time donné par simtime dans le main qui correspond au temps du spike
	cerr<<"delay= "<<delay_count<<endl;
	size_t t(time%(delay_count+1));
	buffer[t]+=J;
	for(size_t i(0);i<buffer.size();++i){
		cout<<"in buffer:"<<buffer[i]<<endl;
	}
}

Neuron::Neuron() : V_reset(0.0),V_thr(20.0), tau(20.0), ref_t(2.0), h(0.1), R(20.0), c1(exp(-h/tau)), c2(R*(1-c1)), D(1.5), nb_spikes(0) ,refractory_count(ref_t/h)//Initialiser a 0???
,delay_count(D/h), buffer(delay_count+1), n_clock(0),excitatory(true)
{}
