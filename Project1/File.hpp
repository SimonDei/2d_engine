#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "FileAccess.hpp"
#include "Disposable.hpp"


namespace sde {
	class File : public Disposable {
		private:
			ALLEGRO_FILE* m_file{ nullptr };
			std::unordered_map<unsigned int, std::string> m_lines{ };
			FileAccess m_access{ };
			std::string m_path{ };

			void read();


		public:
			File() = default;
			explicit File(const std::string& path);
			File(const std::string& path, const FileAccess& access);
			~File();

			/**
			  * Opens the file only for reading from it.
			  * The file will be disposed after reading.
			  * @param path - The path to the file to be red.
			**/
			void open(const std::string& path);

			/**
			  * Opens the file for the access specified.
			  * If the access is not read only it has to be disposed to prevent memory leaks.
			  * @param path - The path to the file to be red.
			  * @param access - The access to be used for the file.
			**/
			void open(const std::string& path, const FileAccess& access);

			void write(const std::string& line) const;
			void write(int offset, const std::string& line) const;

			void writeln(const std::string& line) const;
			void writeln(int offset, const std::string& line) const;

			const std::string& get_line(unsigned int index) const;
			const std::pair<unsigned int, std::string>& get_line_by_filter(const std::string& filter);
			const std::pair<unsigned int, std::string>& get_line_by_filter_with_index(const std::string& filter, unsigned int start_index);

			void dispose() override;
	};
}

#endif