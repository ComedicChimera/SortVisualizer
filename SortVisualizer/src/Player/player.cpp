#include "player.h"

Player::Player(int max) 
	: m_Max(max + 1)
{
	m_Sample.loadFromFile("data/sample.wav");
}

Player::~Player() {
	while (m_Sounds.size() > 0) {
		m_Sounds.back().stop();
		m_Sounds.pop_back();
	}
		
}

float Player::convertToPitch(int value) {
	return 2.0 * (value / (float)m_Max) + 0.01;
}

void Player::playValue(int value) {
	m_Sounds.remove_if([](sf::Sound s) -> bool {
		return s.getStatus() == sf::Sound::Stopped || s.getPlayingOffset().asMilliseconds() > 100;
	});

	float pitch = convertToPitch(value);
	
	sf::Sound sound;
	sound.setBuffer(m_Sample);
	sound.setPitch(pitch);
	sound.setVolume(10);

	m_Sounds.push_back(sound);
	m_Sounds.back().play();
}