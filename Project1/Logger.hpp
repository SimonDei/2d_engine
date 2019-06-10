#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <iostream>


namespace sde {
	namespace logger {
		extern bool DEBUG;


		inline void set_debug_enable(bool debug) {
			DEBUG = debug;
		}

		//================================================
		// Normale Funktionen für Logging Nachrichten
		//================================================
		inline void log(const std::string& message) {
			std::cout << message << std::endl;
		}

		inline void error(const std::string& message) {
			std::cerr << message << std::endl;
		}

		//=========================================================
		// Nachrichten für das Logging nur wenn DEBUG true ist
		//=========================================================
		inline void debug_log(const std::string& message) {
			if (DEBUG) {
				std::cout << "[DEBUG] " << message << std::endl;
			}
		}

		inline void debug_error(const std::string& message) {
			if (DEBUG) {
				std::cerr << "[DEBUG] " << message << std::endl;
			}
		}

		inline void debug_error_and_close(const std::string& message) {
			if (DEBUG) {
				std::cerr << "[DEBUG] " << message << std::endl << "Press any key to close" << std::endl;
				std::getchar();
				std::exit(-1);
			}
		}
	}
}

#endif