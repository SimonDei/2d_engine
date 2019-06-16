#include "Updater.hpp"


namespace sde {
	void Updater::add_updateable(Updateable* updateable) {
		m_update_vector.emplace_back(updateable);
	}

	unsigned int Updater::get_size() const {
		return static_cast<unsigned int>(m_update_vector.size());
	}
	
	void Updater::update(double delta) {
		for (auto& it : m_update_vector) {
			it->update(delta);
		}
	}

	Updater::~Updater() {
	}
}
