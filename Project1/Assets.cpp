#include "Assets.hpp"


namespace sde {
	Assets::Assets(Assets& assets)
	{
		if (m_textures.empty() &&
			m_music.empty() &&
			m_texture_sheets.empty() &&
			m_fonts.empty()) {
			*this = assets;
		} else {
			throw SdeException{ "Assets konnte nicht zugewiesen werden. Es sind bereits Werte vorhanden." };
		}		
	}

	void Assets::load_music(const std::string& name, const std::string& path) {
		m_music.insert(std::make_pair(name, MusicStruct{ path }));
	}

	void Assets::load_texture(const std::string& name, const std::string& path) {
		m_textures.insert(std::make_pair(name, TextureStruct{ path }));
	}

	void Assets::load_texture_sheet(const std::string& name, const std::string& path, unsigned int tile_width, unsigned int tile_height) {
		m_texture_sheets.insert(std::make_pair(name, std::make_shared<TextureSheet>(path, tile_width, tile_height)));
	}

	void Assets::load_font(const std::string& name, const std::string& path) {
		m_fonts.insert(std::make_pair(name, std::make_shared<Font>(path, 12)));
	}

	void Assets::load_font(const std::string& name, const std::string& path, unsigned int size) {
		m_fonts.insert(std::make_pair(name, std::make_shared<Font>(path, size)));
	}

	const Music& Assets::get_music(const std::string& name) {
		if (m_music.at(name).m_loaded) {
			return m_music.at(name).m_music;
		}
		m_music.at(name).load_music();
		return m_music.at(name).m_music;
	}

	const Texture& Assets::get_texture(const std::string& name) {
		if (m_textures.at(name).m_loaded) {
			return m_textures.at(name).m_texture;
		}
		m_textures.at(name).load_texture();
		return m_textures.at(name).m_texture;
	}

	const TextureSheet& Assets::get_texture_sheet(const std::string& name) const {
		if (m_texture_sheets.at(name) != nullptr) {
			return *m_texture_sheets.at(name);
		}
		throw SdeException{ "Texture sheet " + name + " does not exist." };
	}

	const Font& Assets::get_font(const std::string& name) const {
		if (m_fonts.at(name) != nullptr) {
			return *m_fonts.at(name);
		}
		throw SdeException{ "Font " + name + " does not exist." };
	}

	void Assets::dispose_music(const std::string& name) {
		m_music.erase(name);
	}

	void Assets::dispose_texture(const std::string& name) {
		m_textures.erase(name);
	}

	void Assets::dispose_font(const std::string& name) {
		m_fonts.at(name)->dispose();
		m_fonts.erase(name);
	}

	void Assets::dispose() {
		for (auto& font : m_fonts) {
			font.second->dispose();
		}
		for (auto& texturesheet : m_texture_sheets) {
			texturesheet.second->dispose();
		}
	}
}
