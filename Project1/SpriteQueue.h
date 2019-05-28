#pragma once

#include <string>
#include <unordered_map>

#include "Sprite.h"


namespace sde {
	class SpriteQueue {
		private:
			std::unordered_map<unsigned int, Sprite*> m_sprite_map;

		public:
			SpriteQueue() = default;
			~SpriteQueue();

			void push_sprite(const Sprite& sprite);
			void push_sprite(const std::string& path, float x, float y);

			const std::unordered_map<unsigned int, Sprite*>& get_sprite_map() const;
	};
}
