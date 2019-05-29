#pragma once

#include <exception>


namespace sde {
	class NullException : public std::exception {
		private:
		
		public:
			NullException(const std::string& message) : std::exception(message.c_str()) { }
	};
}