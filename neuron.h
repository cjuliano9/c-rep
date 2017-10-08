#ifndef NEURON_HPP
#define NEURON_HPP	
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neuron {
	
	private: //C=250?
	
	double V;		//membrane potential
	double V_reset;
	double tau; //ms
	double ref_t;
	double h; 
	double R; //resistance R=tau/c
	int nb_spikes;
	vector<double> tab_spikes;	//pour stocker le temps des spikes
	
	
	
	public:
	//CONSTRUCTEUR/DESTRUCTEUR//
	
	Neuron(): V_reset(0.0), tau(20.0), ref_t(2.0), R(1.0), nb_spikes(0)
	{}
		
	~Neuron(){
	}
	
	//GETTER//
	
	double getPot() const;
	int getSpikes() const;
	vector<double> getTime() const;
	double getH() const;
	double getV() const;
	
	//SETTER//
	
	void setV(double v);
	
	//METHODE UPDATE//
	
	void update(int input_current);
	
	//VARIABLES PUBLICS??
	
	double c1=exp(-h/tau);
	double c2=R*(1-c1);
	
	//AUTRES METHODES
	
	void count_spikes(double t);
	
	
};

#endif
