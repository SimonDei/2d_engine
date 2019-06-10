#ifndef _FILE_HPP_
#define _FILE_HPP

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Logger.hpp"
#include "FileAccess.hpp"
#include "Disposable.hpp"


namespace sde {
	class File : public Disposable {
		private:
			ALLEGRO_FILE* m_file = nullptr;
			std::string m_path;
			FileAccess m_access;
			bool m_closed = false;
			std::unordered_map<unsigned int, std::string> m_lines;

			void read();

		public:
			File() = default;
			File(const std::string& path);
			File(const std::string& path, const FileAccess& access);
			~File();

			void open(const std::string& path);
			void open(const std::string& path, const FileAccess& access);

			void write(const std::string& line);
			void write(int offset, const std::string& line);

			const std::string& get_line(unsigned int index) const;
			const std::pair<unsigned int, std::string>& get_line_by_filter(const std::string& filter);
			const std::pair<unsigned int, std::string>& get_line_by_filter_with_index(const std::string& filter, unsigned int start_index);

			void dispose() override;
	};
}

#endif