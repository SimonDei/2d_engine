#include "SubTexture.h"


namespace sde {
	SubTexture::SubTexture(ALLEGRO_BITMAP* texture_sheet, float x, float y, float width, float height) {
		m_region_x = x;
		m_region_y = y;
		m_width = width;
		m_height = height;
		m_bitmap = al_create_sub_bitmap(texture_sheet, x, y, width, height);
	}

	void SubTexture::dispose() {
		if (m_bitmap != nullptr && !m_disposed) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_disposed = true;
		}
	}

	SubTexture::~SubTexture() {
	}
}