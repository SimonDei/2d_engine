#include "Updater.hpp"


namespace sde {
	void Updater::add_updateable(std::shared_ptr<Updateable> updateable) {
		if (true) {
			m_update_vector.push_back(updateable);
		} else {
			throw NullException("T is not convertible to Updateable.");
		}
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
