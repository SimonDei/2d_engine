#ifndef _SAVEGAME_HPP_
#define _SAVEGAME_HPP_

#include "File.hpp"


namespace sde {
	class Savegame : public File {
		private:


		public:
			Savegame() = default;
			~Savegame();
	};
}

#endif