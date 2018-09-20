#pragma once

#include <vector>
#include <future>
#include <list>

class BeepThread {
	std::future<void> m_Future;

public:
	BeepThread(int, int);

	bool done();
};


class Player {
	std::list<BeepThread> m_Beeps;

	int m_Max;

	float convertToFreq(int);

public:
	Player(int);
	~Player();

	void playValue(int);
};