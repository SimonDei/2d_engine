#ifndef _SDEEXCEPTION_HPP_
#define _SDEEXCEPTION_HPP_

#include <exception>


namespace sde {
	class SdeException : public std::exception {
		private:
		
		public:
			SdeException(const std::string& message) : std::exception(message.c_str()) { }
	};
}

#endif