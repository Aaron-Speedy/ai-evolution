#include <iostream> 
#include <math.h>
#include <vector>
#include "headers/connection.h"
#include "headers/neuron.h"
#include "headers/brain.h"
int main() {
	Brain brain = Brain(); 
	Connection connection; 
	connection.weight = 2.8; 
	connection.index = 0; 
	connection.mode = 0; 
	brain.out[0].connections.push_back(connection); 
	brain.compute(); 
	std::cout << brain.out[0].value; 
	return 0;
}
