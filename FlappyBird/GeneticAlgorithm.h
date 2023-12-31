#pragma once

#include <vector>
#include <algorithm>
#include "DEFINITIONS.hpp"

class Chrom
{
public:
	Chrom()
	{
		_bias = 0.0f;
		_score = 0;
	}

	std::vector<float> _weights;
	float _bias;
	int _score;
};

class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

	void UpdateGA();

	void Sort();

	void Crossover();

	void Mutate();
	void Mutate(int index);

	float RandFrom(float min, float max);
	float RandInRange(float val, float range);

	void SetChromScore(int index, int score) { _chroms[index]->_score = score; }

	std::vector<Chrom*> GetChroms() { return _chroms; }
private:
	void evpop();

	const float _weightsMin = -0.7f;
	const float _weightsMax = 0.7f;

	std::vector<Chrom*> _chroms;


};