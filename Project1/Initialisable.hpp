#ifndef _INITIALISABLE_HPP_
#define _INITIALISABLE_HPP_


namespace sde {
	class Initialisable {
		private:


		public:
			Initialisable() = default;
			~Initialisable() { };

			virtual void initialise() = 0;
	};
}

#endif