#include "SpriteQueue.hpp"


namespace sde{
	void SpriteQueue::push_sprite(const Sprite& sprite) {
		m_sprite_map.insert(std::make_pair(m_sprite_map.size(), std::make_shared<Sprite>(sprite)));
	}

	void SpriteQueue::push_sprite(const std::string& path, float x, float y) {
		
	}
	
	const std::unordered_map<unsigned int, std::shared_ptr<Sprite>>& SpriteQueue::get_sprite_map() const {
		return m_sprite_map;
	}

	SpriteQueue::~SpriteQueue() {
	}
}
