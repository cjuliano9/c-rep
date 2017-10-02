#include <iostream>
using namespace std;

int main(){
	
	Neuron n1;
	double simtime(0);
	double t_stop; //initialiser
	const double Vpot=-55;
	
	while (simtime<t_stop){
		/*input_current=I(t)*/
		if (){
			V=0;
		}	else if (double getV()>Vpot){
			n1.update(1);
		}
		simtime+=n1.getH();
	}
							//if neuron is refractory->V=0 else if(v>v(threshold)) store spike time 
						V=c1*V+c2*I;					//equation V=V(t+h)
	
	
	return 0;
}
