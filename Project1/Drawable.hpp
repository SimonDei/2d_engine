#ifndef _DRAWABLE_HPP_
#define _DRAWABLE_HPP_

#include "Vector2.hpp"


namespace sde {
	class Drawable {
		private:
		

		protected:


		public:
			Drawable() = default;
			~Drawable() { };
			
			virtual void draw() const = 0;
			virtual void draw(float x, float y) const = 0;
	};
}

#endif