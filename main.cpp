#include <iostream>
#include <fstream>
#include <random>
#include "neuron.cpp"
using namespace std;


int main(){

	double J_excitatory(0.1);
	double J_inhibitory(0.5);

	int nb_excitatory(10000);
	int nb_inhibitory(2500);
	int nb_neurons(nb_excitatory+nb_inhibitory);

	int excitatory_connexion(1000);
	int inhibitory_connexion(250);

	vector<Neuron> tab_neurons(nb_neurons);
	vector<vector<bool> > connexion (nb_neurons*nb_neurons) ;


	for (int i(0);i<nb_neurons; ++i){
		if (i<nb_excitatory) {
		tab_neurons[i].setJ(J_excitatory);
		}
		else {
		tab_neurons[i].setJ(J_inhibitory);
		//excitatory=false;
		}
	}

	random_device device;
	mt19937 gen(device());
	bernoulli_distribution d(0.5);

for (size_t i(0);i<tab_neurons.size();++i){
	int compt(0);
while (compt<excitatory_connexion){
for (int j(0);j<nb_excitatory;++j){
			if (i==j){
				connexion[i][j]=false;
			}
			else{
			bool outcome = d(gen);
			connexion[i][j]=outcome;
			}
			if (connexion[i][j]==true){
				tab_neurons[i].setIndex(j);
				compt++;
			}
		}
	}
	compt=0;
	while (compt<inhibitory_connexion){
		for(size_t k(0); nb_excitatory<k<tab_neurons.size();++k){
			if (i==k){
				connexion[i][k]=false;
			}
			else{
			bool outcome = d(gen);
			connexion[i][k]=outcome;
			}
			if (connexion[i][k]==true){
				tab_neurons[i].setIndex(k);
			}
		}
	}
}

	int simtime(0);

	const double t_start(0.0);
	const double t_stop(20.0);
	ofstream file;
	bool spike; //=n.update()

	 int time_steps((t_stop-t_start)/0.1);

	file.open("potential.txt");

	if(file.fail()){
		cerr<<"Error when opening the file"<<endl;
	}	else{

		while (simtime<time_steps){				//changed from time stop to time step

			for (size_t i(0);i<tab_neurons.size();++i){ 
			spike=tab_neurons[i].update(simtime,0.0);			//regarde si spike ou pas (booléen renvoyé par update)
			file<<"Neuron "<<i<<" :"<<tab_neurons[i].getPot()<<endl;

			cout<<"Neuron "<<i<<" :"<<tab_neurons[i].getPot()<<endl;

				if (spike==true){
					for (size_t j(0); j<tab_neurons[i].getSize(); ++j){
						int t(tab_neurons[i].getIndex(j));
								tab_neurons[t].receive(simtime+tab_neurons[t].getD());		//send the signal to the target neuron and register J in buffer
				}
			}
		}
			simtime++;					//increase global clock
		}
	}

	file.close();

	return 0;
}
