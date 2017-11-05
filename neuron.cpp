#include "neuron.h"

Neuron::Neuron() : V_reset(0.0),V_thres(20.0), tau(20.0), ref_time(2.0), R(20.0), h(0.1), c1(exp(-h/tau)), c2(R*(1-c1)), D(1.5),J_ext(0.1), nb_spikes(0) ,refractory_count(0)
,delay_count(D/h), buffer(delay_count+1)
{}

/**
* @param int time, double input_current
* @return bool spike
*/
bool Neuron::update(int time,double input_current){

	if (refractory_count>0.0){
		V=V_reset;
		refractory_count--;
		buffer[time%(delay_count+1)]=0.0;
		return false;
	}
	 else{

		 static random_device rd;
		 static mt19937 gen(rd());
		 static poisson_distribution<> d(nu_eta);

		 synaptic_current=buffer[time%(delay_count+1)]+J_ext*d(gen);
		 V=c1*V+c2*input_current+synaptic_current;
		 buffer[time%(delay_count+1)]=0.0;

		 	if (V>V_thres){
			count_spikes(time);
			V=V_reset;
			refractory_count=(ref_time/h);

			return true;
			}

			else{
				return false;
			}
		}
}
/**
* @param int time, double current
* @return void;
*/
void Neuron::receive(int time, double current){
	size_t t((time+delay_count)%buffer.size());
	assert(t<buffer.size());
	buffer[t]+=current;
}
/**
* @param double t
* @return void
*/
void Neuron::count_spikes(int t){
	nb_spikes+=1;
	tab_spikes.push_back(t*h);
}
/**
* @return double V
*/
double Neuron::getPot() const{
	return V;
}
/**
* @return int nb_spikes
*/
int Neuron::getSpikes() const{
	return nb_spikes;
}
/**
* @return double h
*/
 double Neuron::getH() const{
	 return h;
 }
 /**
 * @return int delay_count
 */
 int Neuron::getD() const{
	 return delay_count;
 }
/**
* @param double j
* @return void;
*/
void Neuron::setJ(double j){
	J=j;
}
/**
* @param double j
* @return void;
*/
void Neuron::setJext(double j){
	J_ext=j;
}
/**
* @return double J;
*/
double Neuron::getJ() const{
	return J;
}
/**
* @param int i
* @return int connexion_index[i];
*/
int Neuron::getIndex(int i) const{
	return connexion_index[i];
}
/**
* @return size_t connexion_index.size();
*/
size_t Neuron::getConnectSize() const{
	return connexion_index.size();
}
/**
* @param int i
* @return double;
*/
double Neuron::getBufferValue(int i) const{
	return buffer[i];
}
/**
* @return int;
*/
int Neuron::getRefCount() const{
	return refractory_count;
}
/**
* @param int j
* @return void;
*/
void Neuron::setIndex(int j){
	connexion_index.push_back(j);
}
/**
* @param int eta
* @return void;
*/
void Neuron::setEta(double eta){
nu_eta=eta;
}
