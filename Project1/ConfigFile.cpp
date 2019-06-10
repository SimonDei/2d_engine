#include "ConfigFile.hpp"


namespace sde {
	ConfigFile::ConfigFile(const std::string& path) {
		m_path = path;
		m_config_file = al_fopen(m_path.c_str(), "r+");
		char buffer[1024];
		std::string line;
		while ((al_fgets(m_config_file, buffer, 1024)) != 0) {
			line = std::string(buffer);
			line = line.substr(0, line.find_first_of('\n', 0));
			switch (buffer[0]) {
				case '#':
				case '\n':
					break;
				case '[':
					m_section_name = line.substr(1, line.length() - 2);
					m_config_map.insert(std::make_pair(m_section_name, std::unordered_map<std::string, std::string>()));
					break;
				default:
					m_entry_name = line.substr(0, line.find_first_of("=", 0) - 1);
					m_entry_value = line.substr(line.find_first_of("=", 0) + 2, line.length() - 1);
					m_config_map.find(m_section_name)->second.insert(std::make_pair(m_entry_name, m_entry_value));
					break;
			}
		}
	}
	
	const std::unordered_map<std::string, std::string>& ConfigFile::get_section_map(const std::string& map_name) {
		return m_config_map.at(map_name);
	}

	const std::string& ConfigFile::get_section_value(const std::string& map_name, const std::string& pair_key) {
		return m_config_map.at(map_name).at(pair_key);
	}

	void ConfigFile::dispose() {
		if (!m_closed && m_config_file != nullptr) {
			al_fclose(m_config_file);
			m_config_file = nullptr;
			m_closed = true;
		}
	}

	ConfigFile::~ConfigFile() {
		if (!m_closed && m_config_file != nullptr) {
			al_fclose(m_config_file);
			m_config_file = nullptr;
			m_closed = true;
		}
	}
}