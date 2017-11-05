#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#include <iostream>
#include "neuron.h"
#include <cassert>
#include <fstream>

using namespace std;

class Experiment{

private:
  double eta; //!< to stock the eta value given by user
  double g; //!< ratio of J_inhibitory/J_ext
  int simtime; //!< time of the simulation
  const double h; //!< each time step
  double t_start;  //!< starting time
  double t_stop; //!< end time
  int time_steps; //!< time steps
  ofstream file; //!< file to register the neurons and their spikes

  double J_excitatory; //!< amplitude of excitatory neurons
  double J_inhibitory; //!< amplitude of inhibitory neurons
  bool spike; //!< takes the value returned by update function, tells if spike or not

  int nb_excitatory; //!< number of excitatory neurons
  int nb_inhibitory; //!< number of inhibitory neurons
  int nb_neurons; //!< total number of neurons
  int excitatory_connexion; //!< number of excitatory connexions
  int inhibitory_connexion; //!< number of inhibitory connexions
  vector<Neuron> tab_neurons; //!< tab of all neurons

public:
  Experiment (); //!< constructor
  ~Experiment(){ //!< destructor
  }
  void setNetwork(); //!< build up the network , connexion between neurons
  void updateNetwork(); //!< updates each neuron of the network
  void setTime(const double t_init,const double t_fin); //!< set the time of the simulation in time steps
  void simulation(); //!< calls update network at each time step

};

#endif
