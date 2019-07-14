#ifndef _DRAWABLE_HPP_
#define _DRAWABLE_HPP_


namespace sde {
	class Drawable {
		public:
			Drawable() = default;
			virtual ~Drawable() = default;
			
			virtual void draw() const = 0;
			virtual void draw(float x, float y) const { };
	};
}

#endif