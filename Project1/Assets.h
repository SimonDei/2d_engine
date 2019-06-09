#ifndef _ASSETS_H_
#define _ASSETS_H_

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Music.h"
#include "Texture.h"
#include "TextureSheet.h"
#include "Disposable.h"


namespace sde {
	class Assets : public Disposable {
		private:
			std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
			std::unordered_map<std::string, std::shared_ptr<Music>> m_music;
			std::unordered_map<std::string, std::shared_ptr<TextureSheet>> m_texture_sheets;


		public:
			Assets() = default;
			explicit Assets(Assets& assets);
			~Assets();

			void load_music(const std::string& name, const std::string& path);
			void load_texture(const std::string& name, const std::string& path);
			
			void load_texture_sheet(const std::string& name, const std::string& path);
			
			const Music& get_music(const std::string& name) const;
			const Texture& get_texture(const std::string& name) const;
			TextureSheet& get_texture_sheet(const std::string& name);

			void dispose() override;
	};
}

#endif