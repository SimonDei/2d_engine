#pragma once


namespace sde {
	class Drawable {
		private:


		public:
			Drawable() = default;
			~Drawable() { };
			
			virtual void draw() const = 0;
			virtual void draw(float x, float y) const = 0;
	};
}