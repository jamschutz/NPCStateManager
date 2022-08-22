#pragma once

#include <string>

namespace NPCManager
{
	enum Emotion {
		Happy,
		Sad,
		Angry,
		Anxious,
		Surprised,
		Disgusted,
		Afraid
	};


	static std::string emotion_to_string(Emotion emotion) {
		switch (emotion) {
		case Happy:
			return "Happy";
		case Sad:
			return "Sad";
		case Angry:
			return "Angry";
		case Anxious:
			return "Anxious";
		case Surprised:
			return "Surprised";
		case Disgusted:
			return "Disgusted";
		case Afraid:
			return "Afraid";
		default:
			return "Unknown Emotion :(";
		}
	}
}