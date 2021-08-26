#include "prcHead.h"
#include "AudioGame.h"
#include "IOFile.h"



AudioGame::AudioGame() { this->initAudio(); }

AudioGame::~AudioGame() { this->stopBGM(); this->stopSFX(); }

void AudioGame::initAudio()
{
	if (!this->bufferSfx.loadFromFile(IOFile::getMusicSfxDir())) { std::cout << IOFile::getMusicSfxError() << std::endl; }
	else { this->bufferSfx.loadFromFile(IOFile::getMusicSfxDir()); }

	if (!this->bgm.openFromFile(IOFile::getMusicBgmDir())) { std::cout << IOFile::getMusicBgmError() << std::endl; }
	else { this->bgm.openFromFile(IOFile::getMusicBgmDir()); }
}

void AudioGame::playSFX() { this->soundHit.play(); }

void AudioGame::stopSFX() { this->soundHit.stop(); }

void AudioGame::playBGM() { this->bgm.play(); this->bgm.setLoop(true); }

void AudioGame::stopBGM() { this->bgm.stop(); }

void AudioGame::setPitchBGM(int& pitch) { this->bgm.setPitch(pitch); }

void AudioGame::setVolumeBGM(int& vol) { this->bgm.setVolume(vol); }