#pragma once

class AudioGame
{
	private :
		sf::SoundBuffer bufferSfx;
		sf::Sound soundHit;
		sf::Music bgm;

		void initAudio();

	public :
		AudioGame();
		virtual ~AudioGame();

		void playSFX();
		void stopSFX();

		void playBGM();
		void stopBGM();
		void setPitchBGM(int &pitch);
		void setVolumeBGM(int& vol);
};