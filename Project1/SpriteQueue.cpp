#include "SpriteQueue.h"


namespace sde{
	void SpriteQueue::push_sprite(const Sprite& sprite) {
		m_sprite_map.insert(std::make_pair(m_sprite_map.size(), sde_ref_to_ptr(Sprite, sprite)));
	}

	void SpriteQueue::push_sprite(const std::string& path, float x, float y) {
		
	}
	
	const std::unordered_map<unsigned int, Sprite*>& SpriteQueue::get_sprite_map() const {
		return m_sprite_map;
	}

	SpriteQueue::~SpriteQueue() {
	}
}
