#include "synth.h"

Synth::Synth(int amplitude)
	: m_Amplitude(amplitude)
	, m_Loaded(false)
	, m_ClearData(false)
{
	initialize(1, 44100);
}

Synth::Synth(const Synth& other)
	: m_Amplitude(other.m_Amplitude)
	, m_Loaded(false)
	, m_ClearData(false)
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
	for (int i = 0; i < sampleCount; i++) {
		m_AudioData.push_back(m_Amplitude * sin(TAU * (freq / 44100) * i));
	}

	m_Lock.unlock();
}

bool Synth::busy() {
	bool isBusy = false;

	if (m_Lock.try_lock()) {
		isBusy = m_Loaded || m_ClearData;

		m_Lock.unlock();
	}

	return isBusy;
}

