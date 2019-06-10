#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <allegro5/allegro.h>

#include <string>

#include "NullException.hpp"
#include "Disposable.hpp"


namespace sde {
	class Texture : public Disposable {
		protected:
			ALLEGRO_BITMAP* m_bitmap = nullptr;
			float m_width = 0.0f;
			float m_height = 0.0f;


		public:
			Texture() = default;
			explicit Texture(const std::string& path);
			explicit Texture(const Texture& texture);
			explicit Texture(ALLEGRO_BITMAP* al_bitmap);
			Texture(ALLEGRO_BITMAP* al_bitmap, float width, float height, float x, float y);
			~Texture();
			
			void load_texture(const std::string& path);

			float get_width() const;
			float get_height() const;

			ALLEGRO_BITMAP* get_texture() const;

			void dispose() override;
	};
}

#endif