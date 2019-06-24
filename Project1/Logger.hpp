#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <string>
#include <iostream>
#include <fstream>


namespace sde {
	namespace logger {
		static bool log_debug{ false };
		static bool log_to_file{ false };
		static std::ofstream log_file{ };


		inline void set_debug_enable(bool debug) {
			log_debug = debug;
		}

		inline void set_log_to_file(bool file_logging) {
			log_to_file = file_logging;
			if (log_to_file) {
				log_file.open("logfile.log", std::ios::out);
			}
		}

		inline void close() {
			log_file.close();
		}

		//================================================
		// Normale Funktionen für Logging Nachrichten
		//================================================
		inline void log(const std::string& message) {
			if (log_to_file) {
				log_file << message << std::endl;
				return;
			}
			std::cout << message << std::endl;
		}

		inline void error(const std::string& message) {
			if (log_to_file) {
				log_file << message << std::endl;
				return;
			}
			std::cerr << message << std::endl;
		}

		//=========================================================
		// Nachrichten für das Logging nur wenn DEBUG true ist
		//=========================================================
		inline void debug_log(const std::string& message) {
			if (log_debug) {
				if (log_to_file) {
					log_file << "[DEBUG] " << message << std::endl;
					return;
				}
				std::cout << "[DEBUG] " << message << std::endl;
			}
		}

		inline void debug_error(const std::string& message) {
			if (log_debug) {
				if (log_to_file) {
					log_file << "[DEBUG] " << message << std::endl;
					return;
				}
				std::cerr << "[DEBUG] " << message << std::endl;
			}
		}

		inline void debug_error_and_close(const std::string& message) {
			if (log_debug) {
				if (log_to_file) {
					log_file << "[DEBUG] " << message << std::endl;
				}
				std::cerr << "Press any key to close" << std::endl;
				std::getchar();
				std::exit(-1);
			}
		}
	}
}

#endif