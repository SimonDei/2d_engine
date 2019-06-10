#ifndef _UPDATEABLE_HPP_
#define _UPDATEABLE_HPP_


namespace sde {
	class _declspec(dllexport) Updateable {
		private:


		public:
			Updateable() = default;
			~Updateable() { };
			
			virtual void update() = 0;
	};
}

#endif