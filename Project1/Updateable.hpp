#ifndef _UPDATEABLE_HPP_
#define _UPDATEABLE_HPP_


namespace sde {
	class Updateable {
		public:
			Updateable() = default;
			virtual ~Updateable() = default;
			
			virtual void update(float delta) = 0;
	};
}

#endif