#include "Assets.hpp"


namespace sde {
	Assets::Assets(Assets& assets) {
		if (!(m_textures.size() == 0 && m_music.size() == 0 && m_texture_sheets.size() == 0)) {
			throw sde::NullException("Assets konnte nicht zugewiesen werden. Es sind bereits Werte vorhanden.");
		}
		*this = assets;
	}

	void Assets::load_music(const std::string& name, const std::string& path) {
		m_music.insert(std::make_pair(name, std::move(std::make_shared<Music>(path))));
	}

	void Assets::load_texture(const std::string& name, const std::string& path) {
		m_textures.insert(std::make_pair(name, std::move(std::make_shared<Texture>(path))));
	}

	void Assets::load_texture_sheet(const std::string& name, const std::string& path, unsigned int tile_width, unsigned int tile_height) {
		m_texture_sheets.insert(std::make_pair(name, std::move(std::make_shared<TextureSheet>(path, tile_width, tile_height))));
	}

	void Assets::load_font(const std::string& name, const std::string& path) {
		m_fonts.insert(std::make_pair(name, std::move(std::make_shared<Font>(path, 12))));
	}

	void Assets::load_font(const std::string& name, const std::string& path, unsigned int size) {
		m_fonts.insert(std::make_pair(name, std::move(std::make_shared<Font>(path, size))));
	}

	const Music& Assets::get_music(const std::string& name) const {
		if (m_music.at(name) != nullptr) {
			return *m_music.at(name);
		} else {
			throw NullException("Music " + name + " does not exist.");
		}
	}

	const Texture& Assets::get_texture(const std::string& name) const {
		if (m_textures.at(name) != nullptr) {
			return *m_textures.at(name);
		} else {
			throw NullException("Texture " + name + " does not exist.");
		}
	}

	const TextureSheet& Assets::get_texture_sheet(const std::string& name) const {
		if (m_texture_sheets.at(name) != nullptr) {
			return *m_texture_sheets.at(name);
		} else {
			throw NullException("Texture sheet " + name + " does not exist.");
		}
	}

	const Font& Assets::get_font(const std::string& name) const {
		if (m_fonts.at(name) != nullptr) {
			return *m_fonts.at(name);
		} else {
			throw NullException("Font " + name + " does not exist.");
		}
	}

	void Assets::dispose_music(const std::string& name) {
		m_music.at(name)->dispose();
		m_music.erase(name);
	}

	void Assets::dispose_texture(const std::string& name) {
		m_textures.at(name)->dispose();
		m_textures.erase(name);
	}

	void Assets::dispose() {
		for (auto& texture : m_textures) {
			texture.second->dispose();
		}
		for (auto& texturesheet : m_texture_sheets) {
			texturesheet.second->dispose();
		}
		for (auto& music : m_music) {
			music.second->dispose();
		}
		for (auto& font : m_fonts) {
			font.second->dispose();
		}
	}

	Assets::~Assets() {
	}
}
