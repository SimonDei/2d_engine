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
	
	void Animation::update(double delta) {
		if (!m_timer.is_started()) {
			m_timer.start_timer();
		}
		if (m_timer.get_elapsed_ticks() >= m_timer.get_one_second()) {
			m_frame++;
			if (m_frame > m_max_frames) m_frame = 0;
			m_timer.reset();
		}
	}

	void Animation::draw() const {
		al_draw_bitmap(m_texture_sheet->get_texture_rect(m_frame).get_texture(), m_x, m_y, 0);
	}

	void Animation::draw(float x, float y) const {
		al_draw_bitmap(m_texture_sheet->get_texture_rect(m_frame).get_texture(), x, y, 0);
	}

	Animation::~Animation() {
		m_timer.dispose();
	}
}
