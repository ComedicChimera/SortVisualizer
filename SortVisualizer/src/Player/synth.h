#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include <mutex>

class Synth : public sf::SoundStream {
	std::vector<sf::Int16> m_AudioData;
	std::mutex m_Lock;

	bool m_ClearData, m_Loaded, m_Started;

	int m_Amplitude;

	const float TAU = 6.28318;

public:
	Synth(int);
	Synth(const Synth&);
	
	~Synth();

	bool onGetData(sf::SoundStream::Chunk&) override;
	void onSeek(sf::Time) override;

	void makeSound(float, int);
	bool busy();
};