#include "File.h"


namespace sde {
	File::File(const std::string& path) {
		m_path = path;
		m_access = FileAccess::READ;
		m_file = al_fopen(path.c_str(), "r");
		read();
		m_closed = true;
	}

	File::File(const std::string& path, const FileAccess& access) {
		m_path = path;
		m_access = access;
		switch (m_access) {
			case FileAccess::READ:
				m_file = al_fopen(path.c_str(), "r");
				read();
				al_fclose(m_file);
				m_closed = true;
				break;
			case FileAccess::WRITE:
				m_file = al_fopen(path.c_str(), "w+");
				m_closed = false;
				break;
			case FileAccess::READ_WRITE:
				m_file = al_fopen(path.c_str(), "r+");
				m_closed = false;
				read();
				break;
		}
		sde::logger::debug_log("File at: " + m_path + " opened.");
	}

	void File::open(const std::string& path) {
		m_path = path;
		m_access = FileAccess::READ;
		m_file = al_fopen(path.c_str(), "r");
		read();
		m_closed = true;
	}

	void File::open(const std::string& path, const FileAccess& access) {
		m_path = path;
		m_access = access;
		switch (m_access) {
			case FileAccess::READ:
				m_file = al_fopen(path.c_str(), "r");
				read();
				al_fclose(m_file);
				m_closed = true;
				break;
			case FileAccess::WRITE:
				m_file = al_fopen(path.c_str(), "w+");
				m_closed = false;
				break;
			case FileAccess::READ_WRITE:
				m_file = al_fopen(path.c_str(), "r+");
				m_closed = false;
				read();
				break;
		}
		sde::logger::debug_log("File at: " + m_path + " opened.");
	}

	void File::read() {
		char buffer[1024];
		int index = 0;
		while (al_fgets(m_file, buffer, 1024) != 0) {
			m_lines.insert(std::make_pair(index, std::string(buffer)));
			index++;
		}
	}
	
	void File::write(const std::string& line) {
		if (!m_closed) {
			al_fseek(m_file, 0, ALLEGRO_SEEK_END);
			al_fputs(m_file, line.c_str());
			al_fflush(m_file);
		}
	}

	void File::write(int offset, const std::string& line) {
		if (!m_closed) {
			char buffer[1024];
			al_fseek(m_file, 0, ALLEGRO_SEEK_SET);
			for (int i = 0; i <= offset; i++) {
				if (i == offset) {
					al_fputs(m_file, line.c_str());
					al_fflush(m_file);
					break;
				}
				al_fgets(m_file, buffer, 1024);
			}
		}
	}

	const std::string& File::get_line(unsigned int index) const {
		return m_lines.at(index);
	}

	const std::pair<unsigned int, std::string>& File::get_line_by_filter(const std::string& filter) {
		for (std::unordered_map<unsigned int, std::string>::iterator it = m_lines.begin(); it != m_lines.end(); it++) {
			if (it->second == filter) {
				return std::make_pair(it->first, m_lines.at(it->first));
			}
		}
		return std::make_pair(0, "");
	}

	const std::pair<unsigned int, std::string>& File::get_line_by_filter_with_index(const std::string& filter, unsigned int start_index) {
		for (std::unordered_map<unsigned int, std::string>::iterator it = m_lines.begin(); it != m_lines.end(); it++) {
			if (it->first >= start_index) {
				if (it->second == filter) {
					return std::make_pair(it->first, m_lines.at(it->first));
				}
			}
		}
		return std::make_pair(0, "");
	}

	void File::dispose() {
		if (!m_closed) {
			al_fclose(m_file);
			m_file = nullptr;
			m_closed = true;
			sde::logger::debug_log("File at: " + m_path + " closed.");
		}
	}

	File::~File() {
		if (!m_closed) {
			al_fclose(m_file);
			m_file = nullptr;
			m_closed = true;
			sde::logger::debug_log("File at: " + m_path + " closed.");
		}
	}
}
