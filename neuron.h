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
	const double R; //resistance R=tau/c

	int nb_spikes;
	vector<double> tab_spikes;

	double refractory_count;



	public:
	//CONSTRUCTEUR/DESTRUCTEUR//

	Neuron(): V_reset(0.0),V_thr(20.0), tau(20.0), ref_t(2.0), h(0.1), R(20.0), nb_spikes(0) ,refractory_count(ref_t/h)//Initialiser a 0???
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

	//METHODE UPDATE//

	bool update(int time, int input_current);

	//VARIABLES PUBLICS??

	double c1=exp(-h/tau);
	double c2=R*(1-c1);

	//AUTRES METHODES

	void count_spikes(double t);


};

#endif
