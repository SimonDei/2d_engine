#include "Updater.hpp"


namespace sde {
	void Updater::add_updateable(const Updateable& updateable) {
		m_update_vector.push_back(const_cast<Updateable*>(&updateable));
	}

	unsigned int Updater::get_size() const {
		return static_cast<unsigned int>(m_update_vector.size());
	}
	
	void Updater::update() {
		for (auto& it : m_update_vector) {
			it->update();
		}
	}

	Updater::~Updater() {
	}
}
