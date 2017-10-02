#ifndef NEURON_HPP
#define NEURON_HPP	
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neuron {
	
	private: //C=250
	
	double V;		//membrane potential
	const double V_thres;
	int input_current;  //courant
	int nb_spikes;
	vector<double> tab_spikes;	
	
	const double h; //ms
	const double tau; //ms
	const double tau_ref;
	const double c1;
	const double c2;
	const double R; //resistance
	
	
	
	public:
	//CONSTRUCTEUR/DESTRUCTEUR//
	
	Neuron(){
	}
	~Neuron(){
	}
	
	//GETTER//
	
	double getPot() const;
	int getSpikes() const;
	vector<double> getTime() const;
	double getH() const;
	double getV() const;
	
	//SETTER//
	
	//METHODE UPDATE//
	
	void update(int n);
	
	void initialize_current(); //attribue valeur aleatoire au courant
	
};

#endif
