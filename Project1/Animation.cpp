#include "Animation.hpp"


namespace sde {
	Animation::Animation(unsigned int frames) {
		m_max_frames = frames - 1;
	}

	Animation::Animation(unsigned int frames, const TextureSheet& texture_sheet) {
		m_texture_sheet = std::make_shared<TextureSheet>(texture_sheet);
		m_max_frames = frames - 1;
	}
	
	void Animation::set_texture_sheet(const TextureSheet& texture_sheet) {
		m_texture_sheet = std::make_shared<TextureSheet>(texture_sheet);
	}

	void Animation::set_frame_time(double frames_per_sec) {
		m_timer.set_ticks_per_sec(frames_per_sec);
	}
	
	void Animation::update(float delta) {
		if (!m_timer.is_started()) {
			m_timer.start_timer();
		}
		if (m_timer.get_elapsed_time() >= m_timer.get_one_second()) {
			m_frame++;
			if (m_frame > m_max_frames) m_frame = 0;
			m_timer.reset();
		}
	}

	void Animation::draw() const {
		m_texture_sheet->draw_texture_rect(m_frame, m_x, m_y);
	}

	void Animation::draw(float x, float y) const {
		m_texture_sheet->draw_texture_rect(m_frame, x, y);
	}

	Animation::~Animation() {
		m_timer.dispose();
	}
}
