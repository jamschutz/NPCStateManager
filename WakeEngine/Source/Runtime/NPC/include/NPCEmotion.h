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
		Afraid,
		TERMINAL_VALUE // just used to make iterating easier. ALWAYS keep this the last value
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