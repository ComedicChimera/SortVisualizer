#include "player.h"

#include <thread>
#include <chrono>

Player::Player(int max) 
	: m_Max(max + 1)
{
	for (int i = 0; i < 50; i++) {
		m_Synths.push_back(Synth(5000));
	}
}

float Player::convertToFreq(int value) {
	return floor(1000 * (value / (double)m_Max) + 120);
}

void Player::playValue(int value) {
	for (auto &synth : m_Synths) {
		if (!synth.busy()) {
			float frequency = convertToFreq(value);

			synth.makeSound(frequency, 50);

			return;
		}
	}
}