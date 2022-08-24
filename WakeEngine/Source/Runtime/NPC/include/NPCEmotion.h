#pragma once

#include <string>

namespace NPCManager
{
	// NOTE: if you update this, just make sure to update the static methods below!!!!
	enum Emotion {
		Happy = 0,
		Sad = 1,
		Angry = 2,
		Anxious = 3,
		Surprised = 4,
		Disgusted = 5,
		Afraid = 6,
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

	// make sure to keep this in the same order as the enum!!!!
	static const char* EMOTIONS_AVAILABLE[] = {
		"Happy",
		"Sad",
		"Angry",
		"Anxious",
		"Surprised",
		"Disgusted",
		"Afraid"
	};
}