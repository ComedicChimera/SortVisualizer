#include "player.h"

#include <iostream>
#include <thread>
#include <chrono>

Player::Player(int max) 
	: m_Max(max + 1)
{
	for (int i = 0; i < 12; i++) {
		m_Synths.push_back(Synth(10000));
		m_Synths.back().play();
	}
}

float Player::convertToFreq(int value) {
	return floor(900 * (value / (double)m_Max) + 50);
}

void Player::playValue(int value) {
	for (auto &synth : m_Synths) {
		if (!synth.busy()) {
			float frequency = convertToFreq(value);

			synth.makeSound(frequency, 100);

			return;
		}
	}
}