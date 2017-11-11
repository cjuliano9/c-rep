#include "experiment.h"

Experiment::Experiment() : simtime(0), h(0.1), J_excitatory(0.1),  nb_excitatory(10000), nb_inhibitory(2500),
nb_neurons(nb_excitatory+nb_inhibitory),excitatory_connexion(0.1*nb_excitatory),inhibitory_connexion(0.1*nb_inhibitory), tab_neurons(nb_neurons)
{}
 
 /**
  * Setter for the time of the simulation and conversion to time steps
  * @param const double t_init, const double t_fin
  * @return void;
  */ 
void Experiment::setTime(const double t_init,const double t_fin){
  t_start=t_init;
  t_stop=t_fin;
  time_steps=((t_stop-t_start)/h);
}

/**
* Setter of the Network
* Set the number of excitatory and inhibitory neurons and assign them the right amplitude J.
* Set the parameter eta entered by the user for each neuron.
* Then set the target neurons for each neuron using a uniform distribution.
* Each neuron 't' will be the target of (nbr inhibitory connections + nbr excitatory connections) random neurons.
* @return void;
*/ 
void Experiment::setNetwork(){

  for (int i(0);i<nb_neurons; ++i){
		if (i<nb_excitatory) {
		tab_neurons[i].setJ(J_excitatory);
		tab_neurons[i].setEta(eta);
		}
		else {
		tab_neurons[i].setJ(J_inhibitory);
		tab_neurons[i].setEta(eta);
		}
	}

	static random_device device;
	static mt19937 gen(device());
	static uniform_int_distribution<> d1(0,nb_excitatory-1);
	static uniform_int_distribution<> d2(nb_excitatory,nb_neurons-1);

	for (size_t t=0; t<tab_neurons.size();++t){

	for ( int i(0);i<excitatory_connexion;++i){
		auto target= d1(gen);
		tab_neurons[target].setIndex(t);        
	}

	for (int i(0);i<inhibitory_connexion;++i){
			auto target= d2(gen);
			tab_neurons[target].setIndex(t);
		}
	}
}

/**
* The simulation asks the user to enter the value for the graph wanted.
* Two parameters are needed, the nu_ext/nu_threshold ration and the relative weights.
* The parameters are registered in temporary variables used to set parameters for each neuron.
* The method also directly set the inhibitory weight with the relative weight entered.
* Calls setNetwork() to create neurons and connections.
* Calls updateNetwork() at each time step.
* @return void;
*/ 
void Experiment::simulation(){


  cout<<"Enter the ratio of nu_ext/nu_threshold : "<<flush;
  cin>>eta;
  while (cin.fail()){
  cout<<"Please enter a positive number"<<flush;
  cin>>eta;
  }
  assert(eta>0.0); 
  cout<<"Enter the value of g (relative weights) : "<<flush;
  cin>>g;
  while (cin.fail()){
  cout<<"Please enter a number"<<flush;
  cin>>eta;
  } 
  assert (g>0.0);
  J_inhibitory=-g*0.1;
  setNetwork();

  file.open("spikes.txt");

  if(file.fail()){
    cerr<<"Error when opening the file"<<endl;
  }	else{

    while (simtime<time_steps){
      updateNetwork();
      simtime++;
    }
  }

file.close();
}

/**
* For each neuron, calls update and register the returned value in a boolean.
* If  the neuron spikes, register the time of spike and iterates on the tab of connections. 
* Each value in the tab of connections return an index. 
* Calls receive for the neuron given by the index (post-synaptic neuron). 
* @return void;
*/ 
void Experiment::updateNetwork(){
assert(tab_neurons.size() != 0);

for (size_t i(0);i<tab_neurons.size();++i){

	spike=tab_neurons[i].update(simtime,0.0);

	if (spike==true){
    file<<simtime<<'\t'<<i<<'\n';
		for (size_t j(0); j<tab_neurons[i].getConnectSize(); ++j){
		auto t=tab_neurons[i].getIndex(j); 
		tab_neurons[t].receive(simtime,tab_neurons[i].getJ());
		}
  }
}

}
