#ifndef _NULLEXCEPTION_HPP_
#define _NULLEXCEPTION_HPP_

#include <exception>


namespace sde {
	class NullException : public std::exception {
		private:
		
		public:
			NullException(const std::string& message) : std::exception(message.c_str()) { }
	};
}

#endif