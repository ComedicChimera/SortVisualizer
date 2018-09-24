#pragma once

#include <vector>

#include "synth.h"

class Player {
	std::vector<Synth> m_Synths;

	int m_Max;

	float convertToFreq(int);

public:
	Player(int);

	void playValue(int);
};