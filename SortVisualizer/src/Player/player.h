#pragma once

#include <SFML/Audio.hpp>
#include <list>

class Player {
	sf::SoundBuffer m_Sample;
	std::list<sf::Sound> m_Sounds;

	int m_Max;

	float convertToPitch(int);

public:
	Player(int);
	~Player();

	void playValue(int);
};