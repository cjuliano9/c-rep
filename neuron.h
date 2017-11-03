#ifndef NEURON_HPP
#define NEURON_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <cassert>

using namespace std;

class Neuron {


	private:

	double V;		//membrane potential
	const double V_reset;
	const double V_thr;
	const double tau; //ms
	const double ref_t;
	const double h;
	const double R; //resistance R=tau/c
	const double c1;
	const	double c2;
	const double D;
	double J; //amplitude
	const double J_ext;
	double synaptic_current;

	int nb_spikes;
	vector<double> tab_spikes;

	int refractory_count;
	int delay_count;

	const double nu_ext;
	const double nu_eta;

	vector<double> buffer;
	int n_clock;

	vector<int> connexion_index;

	public:

	//bool excitatory;

	//CONSTRUCTEUR/DESTRUCTEUR//

	Neuron();
	~Neuron(){
	}

	//GETTER//

	double getPot() const;
	int getSpikes() const;
	//vector<double> getTime() const;
	double getH() const;
	double getD() const;
	int getIndex(int i) const;
	size_t getSize() const;
	double getJ() const;
	//SETTER//

	void setV(double v);
	void setJ(double j);
	void setIndex(int j);
	//METHODE UPDATE//

	bool update(int time, double input_current);


	//AUTRES METHODES

	void count_spikes(double t);
	void receive(int time, double J_);

	//SURCHARGES D'OPERATEURS
};

#endif
