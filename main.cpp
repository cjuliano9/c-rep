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
	//vector<vector<bool> > connexion (nb_neurons*nb_neurons) ;

	for (int i(0);i<nb_neurons; ++i){
		if (i<nb_excitatory) {
		tab_neurons[i].setJ(J_excitatory);
		}
		else {
		tab_neurons[i].setJ(J_inhibitory);
		//excitatory=false;
		}
	}

	static random_device device;
	static mt19937 gen(device());
	static uniform_int_distribution<> d1(0,9999);
	static uniform_int_distribution<> d2(10000,12499);

	for (size_t t=0; t<tab_neurons.size();++t){

	for (int i(0);i<excitatory_connexion;++i){
		auto target= d1(gen);
		if (target==t){
			i--;
		}
		else{
		tab_neurons[t].setIndex(target);
		}
	}

	for (int i(0);i<inhibitory_connexion;++i){
			auto target= d2(gen);
			if (target==t){
				i--;
			}
			else{
			tab_neurons[t].setIndex(target);
			}
		}

	}


	int simtime(0);

	const double t_start(0.0);
	const double t_stop(10.0);
	ofstream file;
	bool spike; //=n.update()

	 int time_steps((t_stop-t_start)/0.1); //faire une fonction simulation

	file.open("spike.jdf");

	if(file.fail()){
		cerr<<"Error when opening the file"<<endl;
	}	else{

		while (simtime<time_steps){				//changed from time stop to time step

			for (size_t i(0);i<tab_neurons.size();++i){
			spike=tab_neurons[i].update(simtime,0.0);			//regarde si spike ou pas (booléen renvoyé par update)

			//file<<"Neuron "<<i<<" :"<<tab_neurons[i].getPot()<<endl;

				if (spike==true){
				file<<"Time of spike: "<<simtime<<'\t'<<" Neuron: "<<i<<'\n';
					for (size_t j(0); j<tab_neurons[i].getSize(); ++j){ //getsize renvoie la taille du tableau de target
						int t(tab_neurons[i].getIndex(j));
						tab_neurons[t].receive(simtime);		//send the signal to the target neuron and register J in buffer
				}
			}
		}
			simtime++;					//increase global clock
		}
	}

	file.close();

	return 0;
}
