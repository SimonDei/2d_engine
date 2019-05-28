#pragma once


namespace sde {
	class Updateable {
		private:


		public:
			Updateable() = default;
			~Updateable() { };
			
			virtual void update() = 0;
	};
}