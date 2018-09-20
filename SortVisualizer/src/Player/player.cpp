#include "player.h"

Player::Player(int max) 
	: m_Max(max + 1)
{
	m_Sample.loadFromFile("data/sample.wav");
}

Player::~Player() {
	while (m_Sounds.size() > 0) {
		m_Sounds.front().stop();
		m_Sounds.pop();
	}
		
}

float Player::convertToPitch(int value) {
	return 2.0 * (value / (float)m_Max) + 0.01;
}

void Player::playValue(int value) {
	while (m_Sounds.size() > 0 && m_Sounds.front().getStatus() == sf::Sound::Stopped)
		m_Sounds.pop();

	float pitch = convertToPitch(value);
	
	sf::Sound sound;
	sound.setBuffer(m_Sample);
	sound.setPitch(pitch);
	sound.setVolume(5);

	m_Sounds.push(sound);
	m_Sounds.back().play();
}