#pragma once

#include <allegro5/allegro.h>

#include <string>

#include "Disposable.h"


namespace sde {
	class Texture : public Disposable {
		private:
			ALLEGRO_BITMAP* m_bitmap = nullptr;
			float m_width = 0.0f;
			float m_height = 0.0f;


		public:
			Texture() = default;
			explicit Texture(const std::string& path);
			explicit Texture(const Texture& texture);
			explicit Texture(ALLEGRO_BITMAP* al_bitmap);
			~Texture();
			
			void load_texture(const std::string& path);

			float get_width() const;
			float get_height() const;

			ALLEGRO_BITMAP* get_texture() const;

			void dispose() override;
	};
}