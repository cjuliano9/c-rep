#ifndef NEURON_HPP
#define NEURON_HPP
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neuron {


	private:

	double V;		//membrane potential
	const double V_reset;
	const double V_thr;
	const double tau; //ms
	const double ref_t;
	const double h;
	const double I_ext;
	const double R; //resistance R=tau/c
	const double c1;
	const	double c2;
	const double D;
	const double J; //amplitude

	int nb_spikes;
	vector<double> tab_spikes;

	double refractory_count;
	double delay_count;

	vector<int> buffer;
	double n_clock;

	public:
	//CONSTRUCTEUR/DESTRUCTEUR//

	Neuron(): V_reset(0.0),V_thr(20.0), tau(20.0), ref_t(2.0), h(0.1), I_ext(2.0), R(20.0), c1(exp(-h/tau)), c2(R*(1-c1)), D(1.5), J(0.1), nb_spikes(0) ,refractory_count(ref_t/h)//Initialiser a 0???
	,delay_count(D/h), buffer(delay_count+1), postsynaptic(false)
	{}

	~Neuron(){
	}

	//GETTER//

	double getPot() const;
	int getSpikes() const;
	vector<double> getTime() const;
	double getH() const;

	//SETTER//

	void setV(double v);
	bool setDelay(); 						// define the delay steps

	//METHODE UPDATE//

	bool update(int time, double input_current);
	bool update_post(double time,bool isDelay);
	//VARIABLES PUBLICS??

	bool postsynaptic;

	//AUTRES METHODES

	void count_spikes(double t);
};

#endif
