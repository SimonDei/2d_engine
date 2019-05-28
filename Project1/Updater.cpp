#include "Updater.h"


namespace sde {
	void Updater::add_updateable(const Updateable& updateable) {
		m_update_vector.push_back(sde_ref_to_ptr(Updateable, updateable));
	}
	
	void Updater::update() {
		for (auto& it : m_update_vector) {
			it->update();
		}
	}

	Updater::~Updater() {
	}
}
