class Neuron {
	public: 
	std::vector<Connection> connections = {}; 
	float bias = 0; 
	float value = 0; 
	bool sin_bool = 0; 
	bool computed = false; 
	bool compute(std::vector<Neuron>& input, std::vector<Neuron>& internal) {
		for(int i = 0; i < connections.size(); i++) {
			if(connections[i].mode) {
				if(!internal[connections[i].index].computed) return 0; 
				value += internal[connections[i].index].value * connections[i].weight; 
			}
			if(!connections[i].mode) {
				if(!input[connections[i].index].computed) return 0; 
				value += input[connections[i].index].value * connections[i].weight; 
			}
		}
		value += bias; 
		value = tanh(value); 
		if(sin_bool) {
			value = sin(value);
		}
		computed = true; 
		return 1; 
	}
};
