#ifndef _DISPOSABLE_HPP_
#define _DISPOSABLE_HPP_


namespace sde {
	class Disposable {
		protected:
			bool m_disposed{ false };


		public:
			Disposable() = default;
			virtual ~Disposable() = default;;

			virtual void dispose() = 0;
	};
}

#endif