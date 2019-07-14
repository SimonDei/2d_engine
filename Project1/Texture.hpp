#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>

#include <string>
#include <vector>

#include "TextureFlags.hpp"
#include "SdeException.hpp"
#include "Disposable.hpp"


namespace sde {
	class Texture : public Disposable {
		protected:
			ALLEGRO_BITMAP* m_bitmap{ nullptr };
			ALLEGRO_LOCKED_REGION* m_region_data{ nullptr };
			float m_width{ 0.0f };
			float m_height{ 0.0f };
			std::vector<TextureFlags> m_flags{ };


		public:
			Texture() = default;
			explicit Texture(const std::string& path);
			explicit Texture(ALLEGRO_BITMAP* al_bitmap);
			explicit Texture(const std::initializer_list<TextureFlags>& flag_list);
			Texture(ALLEGRO_BITMAP* al_bitmap, float x, float y, float width, float height);
			~Texture() = default;
			
			void load_texture(const std::string& path);

			void lock();
			void lock(int x, int y, int width, int height);
			
			int get_pixel_color(int x, int y) const;

			void unlock();

			float get_width() const;
			float get_height() const;

			ALLEGRO_BITMAP* get_texture() const;
			unsigned int get_gl_texture() const;

			void dispose() override;
	};

	struct TextureStruct {
		std::string m_path{ };
		Texture m_texture{ };
		bool m_loaded{ false };

		void load_texture() {
			m_texture.load_texture(m_path);
		}

		TextureStruct() = default;
		explicit TextureStruct(const std::string& path) {
			m_path = path;
		}
		~TextureStruct() {
			m_texture.dispose();
		}
	};
}

#endif