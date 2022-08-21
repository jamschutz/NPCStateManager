#pragma once

#include "../include/Debug.h"
#include <iostream>
#include <string>
#include <fstream>



/* =======================================================================  /
/  =======	   Public Methods				==============================  /
/  ======================================================================= */

void Wake::Debug::log(const std::string& message) {
	std::cout << message << std::endl;
}


void Wake::Debug::log_warning(const std::string& message) {
	std::cout << message << std::endl;
}


void Wake::Debug::log_error(const std::string& message) {
	std::cout << message << std::endl;
}

void Wake::Debug::log(const std::string& message, const std::string& method) {
	std::cout << message << std::endl << "from: " << method << std::endl << std::endl;
}


void Wake::Debug::log_warning(const std::string& message, const std::string& method) {
	std::cout << message << std::endl << "from: " << method << std::endl << std::endl;
}


void Wake::Debug::log_error(const std::string& message, const std::string& method) {
	std::cout << message << std::endl << "from: " << method << std::endl << std::endl;
}



/* =======================================================================  /
/  =======	   Helper Methods				==============================  /
/  ======================================================================= */