#pragma once

#include <string>

namespace Wake {
	static class Debug {
	public:
		static void log(const std::string& message);
		static void log_warning(const std::string& message);
		static void log_error(const std::string& message);

		static void log(const std::string& message, const std::string& method);
		static void log_warning(const std::string& message, const std::string& method);
		static void log_error(const std::string& message, const std::string& method);

	private:
	};
}