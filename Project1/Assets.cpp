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

	void Assets::load_texture_sheet(const std::string& name, const std::string& path) {
		m_texture_sheets.insert(std::make_pair(name, std::move(std::make_shared<TextureSheet>(path))));
	}

	const Music& Assets::get_music(const std::string& name) const {
		return *m_music.at(name).get();
	}

	const Texture& Assets::get_texture(const std::string& name) const {
		return *m_textures.at(name).get();
	}

	TextureSheet& Assets::get_texture_sheet(const std::string& name) {
		return *m_texture_sheets.at(name).get();
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
	}

	Assets::~Assets() {
	}
}
