#include "player.h"

#include <windows.h>
#include <thread>

using namespace std::chrono_literals;

BeepThread::BeepThread(int freq, int duration) {
	m_Future = std::async(std::launch::async, [=]() {
		Beep(freq, duration);
	});
}

bool BeepThread::done() {
	return m_Future.wait_for(0ms) == std::future_status::ready;
}

Player::Player(int max) 
	: m_Max(max + 1)
{}

Player::~Player() {
	while (m_Beeps.size() > 0) {
		m_Beeps.pop_back();
	}	
}

float Player::convertToFreq(int value) {
	return floor(900 * (value / (double)m_Max) + 50);
}

void Player::playValue(int value) {
	m_Beeps.remove_if([](BeepThread &item) -> bool { return item.done(); });

	m_Beeps.push_back(BeepThread(convertToFreq(value), 100));

	// possibly remove
	std::this_thread::sleep_for(5ms);
}