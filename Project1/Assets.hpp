#ifndef _ASSETS_HPP_
#define _ASSETS_HPP_

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Music.hpp"
#include "Texture.hpp"
#include "TextureSheet.hpp"
#include "Font.hpp"
#include "Disposable.hpp"


namespace sde {
	class Assets : public Disposable {
		private:
			std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures{ };
			std::unordered_map<std::string, std::shared_ptr<Music>> m_music{ };
			std::unordered_map<std::string, std::shared_ptr<TextureSheet>> m_texture_sheets{ };
			std::unordered_map<std::string, std::shared_ptr<Font>> m_fonts{ };


		public:
			Assets() = default;
			explicit Assets(Assets& assets);
			~Assets();

			void load_music(const std::string& name, const std::string& path);
			void load_texture(const std::string& name, const std::string& path);
			void load_texture_sheet(const std::string& name, const std::string& path);
			void load_font(const std::string& name, const std::string& path);
			void load_font(const std::string& name, const std::string& path, unsigned int size);

			const Music& get_music(const std::string& name) const;
			const Texture& get_texture(const std::string& name) const;
			TextureSheet& get_texture_sheet(const std::string& name);
			const Font& get_font(const std::string& name) const;

			void dispose() override;
	};
}

#endif