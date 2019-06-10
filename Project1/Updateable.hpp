#ifndef _UPDATEABLE_HPP_
#define _UPDATEABLE_HPP_


namespace sde {
	class Updateable {
		private:


		public:
			Updateable() = default;
			~Updateable() { };
			
			virtual void update() = 0;
	};
}

#endif