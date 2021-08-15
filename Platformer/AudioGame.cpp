#include "prcHead.h"
#include "AudioGame.h"

AudioGame::AudioGame() { this->initAudio(); }

AudioGame::~AudioGame() { this->stopBGM(); this->stopSFX(); }

void AudioGame::initAudio()
{
	if (!this->bufferSfx.loadFromFile("src/SFX/hit.wav")) { std::cout << "INFO::GAME::SFX:: SFX files not loaded !!" << std::endl; }
	else { this->bufferSfx.loadFromFile("src/SFX/hit.wav"); }

	if (!this->bgm.openFromFile("src/Music/junna.wav")) { std::cout << "INFO::GAME::SFX:: SFX files not loaded !!" << std::endl; }
	else { this->bgm.openFromFile("src/Music/junna.wav"); }
}

void AudioGame::playSFX() { this->soundHit.play(); }

void AudioGame::stopSFX() { this->soundHit.stop(); }

void AudioGame::playBGM() { this->bgm.play(); this->bgm.setLoop(true); }

void AudioGame::stopBGM() { this->bgm.stop(); }

void AudioGame::setPitchBGM(int& pitch) { this->bgm.setPitch(pitch); }

void AudioGame::setVolumeBGM(int& vol) { this->bgm.setVolume(vol); }