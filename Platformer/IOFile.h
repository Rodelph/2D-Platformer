#include <iostream>

#pragma once

class IOFile
{
	private :
		inline static const std::string& playerSheetDir = "src/Texture/player_sheet.png";
		inline static const std::string& playerSheetError = "Info::GAME::Texture:: Failed to load textures";

		inline static const std::string& musicSfxDir = "src/SFX/hit.wav";
		inline static const std::string& musicSfxError = "Info::GAME::SFX:: SFX files not loaded !!";

		inline static const std::string& musicBgmDir = "src/Music/junna.wav";
		inline static const std::string& musicBgmError = "INFO::GAME::BGM:: BGM files not loaded !!";

		inline static const std::string&& gameTitle = "Platformer";

	public:
		static const std::string getPlayerSheetDir();
		static const std::string getPlayerSheetError();
		static const std::string getMusicSfxDir();
		static const std::string getMusicSfxError();
		static const std::string getMusicBgmDir();
		static const std::string getMusicBgmError();
		static const std::string getTitle();
};