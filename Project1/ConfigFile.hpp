#ifndef _CONFIGFILE_HPP_
#define _CONFIGFILE_HPP_

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Disposable.hpp"


namespace sde {
	class ConfigFile : public Disposable {
		private:
			ALLEGRO_FILE* m_config_file = nullptr;
			std::unordered_map<std::string, std::unordered_map<std::string, std::string>> m_config_map;
			std::string m_section_name;
			std::string m_entry_name;
			std::string m_entry_value;
			std::string m_path;
			bool m_closed = false;

		public:
			ConfigFile() = default;
			explicit ConfigFile(const std::string& path);
			~ConfigFile();

			const std::unordered_map<std::string, std::string>& get_section_map(const std::string& map_name);
			const std::string& get_section_value(const std::string& map_name, const std::string& pair_key);

			void dispose() override;
	};
}

#endif