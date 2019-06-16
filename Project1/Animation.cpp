#include "Animation.hpp"


namespace sde {
	void Animation::set_texture_sheet(const TextureSheet& texture_sheet) {
		m_texture_sheet = std::make_shared<TextureSheet>(texture_sheet);
	}

	void Animation::set_frame_time(float frame_time) {
		m_frame_time = frame_time;
	}
	
	void Animation::update(double delta) {

	}
	
	Animation::~Animation() {
	}
}
