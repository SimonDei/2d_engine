#pragma once

#include <allegro5/allegro.h>

#include <string>

#include "Texture.h"
#include "Disposable.h"


namespace sde {
	class SubTexture : public Texture {
		private:
			float m_region_x = 0.0f;
			float m_region_y = 0.0f;


		public:
			SubTexture() = default;
			SubTexture(ALLEGRO_BITMAP* texture_sheet, float x, float y, float width, float height);
			~SubTexture();

			void dispose() override;
	};
}
