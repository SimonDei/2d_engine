#ifndef _SPRITEQUEUE_HPP_
#define _SPRITEQUEUE_HPP_

#include <string>
#include <unordered_map>

#include "Sprite.hpp"


namespace sde {
	class SpriteQueue {
		private:
			std::unordered_map<unsigned int, std::shared_ptr<Sprite>> m_sprite_map{ };


		public:
			SpriteQueue() = default;
			~SpriteQueue();

			void push_sprite(const Sprite& sprite);
			void push_sprite(const std::string& path, float x, float y);

			const std::unordered_map<unsigned int, std::shared_ptr<Sprite>>& get_sprite_map() const;
	};
}

#endif