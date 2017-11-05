#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <cassert>

using namespace std;

class Neuron {


	private:

	double V;		//!< membrane potential
	const double V_reset; //!< reset potential
	const double V_thres; //!< threshold potential
	const double tau; //!< in ms
	const double ref_time; //!< refractory time
	const double R; //!< resistance
	const double h; //!< each time step is h
	const double c1; //!< constant used in potential update
	const double c2; //!< constant used in potential update
	const double D; //!< Delay
	double J; //!< Amplitude of spike
	const double J_ext; //!< external current from background noise
	double synaptic_current; //!< background noise + amplitude

	int nb_spikes; //!< counter for number of spikes

	int refractory_count; //!< internal clock to count the refractory period in time steps
	int delay_count; //!< to count the delay in time steps

	double nu_eta; //!< ratio of nu_ext/nu_threshold

	vector<double> buffer; //!< ring buffer used to stock the delays
	vector<int> connexion_index; //!< tab of the index of neurons targets

	public:

	//CONSTRUCTOR/DESTRUCTOR//

	Neuron(); //!< constructor
	~Neuron(){ //!< destructor
	}

	//GETTERS//

	double getPot() const; //!< return the potential
	int getSpikes() const; //!< return number of spikes
	double getH() const; //!< return the constant h, time step
	int getD() const; //!< return the delay_count
	int getIndex(int i) const; //!<return the index of the tab of targets
	size_t getConnectSize() const; //!< return the size of the tab of targets
	double getJ() const; //!< return the amplitude J

	//SETTERS//

	void setV(double v); //!< set the potential
	void setJ(double j); //!< set the amplitude
	void setIndex(int j); //!< set the tab of index
	void setEta(int eta); //!< set the ratio nu_ext/nu_threshold
	
	//OTHER METHODS//

	bool update(int time, double input_current); //!<update the potential of neuron at each time step and return a boolean if spiking
	void count_spikes(double t);  //!<count the number of spikes and add the time in a tab of spikes
	void receive(int time, double current);  //!<put the value of current in the buffer of target neuron

};

#endif
