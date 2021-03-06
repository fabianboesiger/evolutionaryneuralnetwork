#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <memory>
#include <queue>

#include "data.hpp"

struct Neuron {
	std::queue <float> values;
	unsigned int hold;
};

class Network {

public:
	static const float DELTA_MULTIPLIER;
	static const unsigned int EXPECTED_LAYERS;
	static const unsigned int EXPECTED_LAYER_SIZE;
	static const unsigned int EXPECTED_HOLD;
	static const double HOLD_MUTATION_CHANCE;
	static const double NEURON_MUTATION_CHANCE;
	static const double LAYER_MUTATION_CHANCE;

	Network(Data *);
	Network(std::shared_ptr <Network>);
	Network(Data *, std::ifstream &);
	void train();
	std::vector <float> run(size_t, bool);
	double getError();
	double getErrorDelta();
	double getFitness();
	unsigned int getId();
	unsigned int getGeneration();
	unsigned int getTrainingCount();
	void save(std::ofstream &);
	unsigned int getTotalAxons();

private:
	std::vector <std::vector <Neuron>> neurons;
	std::vector <std::vector <std::vector <float>>> axons;
	float vectorDifference(std::vector <float>, std::vector <float>);
	Data * data;
	void trainAxon(Network*, unsigned int, unsigned int, unsigned int);
	double calculateError();
	double error;
	double errorDelta;
	static float sigmoid(float);
	static float sigmoidReverse(float);
	static unsigned int idCount;
	const unsigned int id;
	unsigned int generation;
	unsigned int trainingCount;
	unsigned int totalAxons;
	void countAxons();

};

#endif