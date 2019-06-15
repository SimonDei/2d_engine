#ifndef _DISPOSABLE_HPP_
#define _DISPOSABLE_HPP_


namespace sde {
	class Disposable {
		private:


		protected:
			bool m_disposed{ false };
			bool m_auto_disposed{ false };


		public:
			Disposable() = default;
			~Disposable() { };

			virtual void dispose() = 0;
	};
}

#endif