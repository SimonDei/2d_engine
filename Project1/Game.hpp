#ifndef _GAME_HPP_
#define _GAME_HPP_


namespace sde {
	class Game {
		public:
			Game() = default;
			virtual ~Game() = default;
			
			virtual void init() = 0;
			virtual void keyboard() = 0;
			virtual void update() = 0;
			virtual void render() = 0;
			virtual void dispose() = 0;
	};
}

#endif