#include "Disposer.hpp"


namespace sde {
	void Disposer::add_disposable(Disposable* disposable) {
		m_dispose_vector.push_back(disposable);
	}

	void Disposer::dispose() {
		if (!m_disposed) {
			for (auto& it : m_dispose_vector) {
				it->dispose();
			}
			m_disposed = true;
		}
	}

	Disposer::~Disposer() {
		if (!m_disposed) {
			for (auto& it : m_dispose_vector) {
				it->dispose();
			}
			m_disposed = true;
		}
	}
}