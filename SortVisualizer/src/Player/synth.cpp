#include "synth.h"

Synth::Synth(int amplitude)
	: m_Amplitude(amplitude)
	, m_Loaded(false)
	, m_ClearData(false)
	, m_Started(false)
{
	initialize(1, 44100);
}

Synth::Synth(const Synth& other)
	: m_Amplitude(other.m_Amplitude)
	, m_Loaded(false)
	, m_ClearData(false)
	, m_Started(false)
{
	initialize(1, 44100);
}

Synth::~Synth() {
	stop();
}

bool Synth::onGetData(Chunk &chunk) {
	static const sf::Int16 empty[10] = { 0 };

	m_Lock.lock();

	if (m_Loaded) {
		chunk.sampleCount = m_AudioData.size();
		chunk.samples = m_AudioData.data();

		m_ClearData = true;
		m_Loaded = false;
	}
	else {
		if (m_ClearData) {
			m_AudioData.clear();
			m_ClearData = false;
		}

		chunk.sampleCount = 10;
		chunk.samples = empty;
	}

	m_Lock.unlock();

	return true;
}

void Synth::onSeek(sf::Time) {}

void Synth::makeSound(float freq, int duration) {
	m_Lock.lock();

	m_ClearData = false;
	m_Loaded = true;

	m_AudioData.clear();

	int sampleCount = duration * 44;
	double x = 0, increment = freq / 44100;
	for (int i = 0; i < sampleCount; i++) {
		m_AudioData.push_back(floor(m_Amplitude * envelope(i, sampleCount) * sin(x * TAU)));
		x += increment;
	}

	m_Lock.unlock();

	if (!m_Started) {
		play();
		m_Started = true;
	}
}

// ASDR Envelope Code -> Credit to Timo Bingmann
// https://github.com/bingmann/sound-of-sorting/blob/master/src/SortSound.cpp
double Synth::envelope(int i, int duration) {
	double x = (double)i / duration;
	if (x > 1.0) x = 1.0;

	static const double attack = 0.025;
	static const double decay = 0.1;
	static const double sustain = 0.9;
	static const double release = 0.3;

	if (x < attack)
		return 1.0 / attack * x;

	if (x < attack + decay)
		return 1.0 - (x - attack) / decay * (1.0 - sustain);

	if (x < 1.0 - release)
		return sustain;

	return sustain / release * (1.0 - x);
}

bool Synth::busy() {
	bool isBusy = false;

	if (m_Lock.try_lock()) {
		isBusy = m_Loaded || m_ClearData;

		m_Lock.unlock();
	}

	return isBusy;
}

