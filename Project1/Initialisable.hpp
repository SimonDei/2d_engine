#ifndef _INITIALISABLE_HPP_
#define _INITIALISABLE_HPP_


namespace sde {
	class Initialisable {
		public:
			Initialisable() = default;
			virtual ~Initialisable() = default;;

			virtual void initialise() = 0;
	};
}

#endif