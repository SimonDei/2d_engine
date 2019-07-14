#ifndef _RENDERTEXTURE_HPP_
#define _RENDERTEXTURE_HPP_

#include <allegro5/allegro.h>

#include "Texture.hpp"
#include "Color3.hpp"
#include "Color4.hpp"
#include "Drawable.hpp"
#include "Disposable.hpp"
#include "Vector2.hpp"


namespace sde {
	class RenderTexture : public Drawable, public Disposable {
		private:
			ALLEGRO_BITMAP* m_bitmap{ nullptr };
			ALLEGRO_DISPLAY* m_display{ nullptr };


		public:
			RenderTexture() = default;
			explicit RenderTexture(const Vector2<unsigned int>& size);
			RenderTexture(unsigned int width, unsigned int height);
			~RenderTexture() = default;

			void create(unsigned int width, unsigned int height);

			void clear_texture(unsigned char red, unsigned char green, unsigned char blue);
			void clear_texture(const Color3<unsigned char>& color);
			void clear_texture(const Color4<unsigned char>& color);

			void draw_to_texture(const Texture& texture);
			void draw_to_texture(const Texture& texture, float x, float y);
			void draw_to_texture(const Texture& texture, float x, float y, float width, float height);

			void draw_to_texture(const Drawable& drawable);
			void draw_to_texture(const Drawable& drawable, float x, float y);

			void draw() const override;
			void draw(float x, float y) const override;

			void dispose() override;
	};
}

#endif