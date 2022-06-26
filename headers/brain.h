class Brain {
	public: 
	std::vector<Neuron> input = {}; 
	std::vector<Neuron> internal = {}; 
	std::vector<Neuron> out = {}; 
	Brain() {
		for(int i = 0; i < 1; i++) {
			Neuron neuron; 
			neuron.computed = true; 
			neuron.value = 1; 
			input.push_back(neuron); 
		}
		for(int i = 0; i < 1; i++) {
			Neuron neuron; 
			out.push_back(neuron); 
		}
	}
	void compute() {
		std::vector<int> needed; 
		for(int i = 0; i < internal.size(); i++) {
			needed.push_back(i); 
		}
		while(needed.size() != 0) {
			std::vector<int> needed_temp = needed; 
			for(int i = 0; i < needed.size(); i++) {
				if(!internal[needed[i]].compute(input, internal)) needed_temp.push_back(needed[i]);
			}
			needed = needed_temp; 
		}
		for(int i = 0; i < out.size(); i++) {
			out[i].compute(input, internal); 
		}
		for(int i = 0; i < internal.size(); i++) {
			internal[i].computed = false; 
		}
	}
};
