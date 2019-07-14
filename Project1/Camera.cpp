#include "Camera.hpp"


namespace sde {
	Camera::Camera(float width, float height) {
		m_width = width;
		m_height = height;
		al_identity_transform(&m_identity);
		al_identity_transform(&m_transform);
	}

	void Camera::apply() {
		al_build_transform(&m_transform, -m_offset_x, -m_offset_y, m_zoom, m_zoom, m_rotation);
		al_use_transform(&m_transform);
	}

	void Camera::reset() {
		al_identity_transform(&m_transform);
		al_use_transform(&m_identity);
		m_offset_x = 0.0f;
		m_offset_y = 0.0f;
		m_rotation = 0.0f;
		m_zoom = 1.0f;
	}

	void Camera::set_camera_bounds(float width, float height) {
		m_width = width;
		m_height = height;
	}

	void Camera::set_auto_apply(bool enabled) {
		m_auto_apply = enabled;
	}

	void Camera::set_x(float x) {
		m_offset_x = x;
		if (m_auto_apply) {
			build_transform();
		}
	}

	void Camera::set_y(float y) {
		m_offset_y = y;
		if (m_auto_apply) {
			build_transform();
		}
	}

	void Camera::set_zoom(float zoom) {
		m_zoom = zoom;
		if (m_auto_apply) {
			build_transform();
		}
	}

	void Camera::add_x(float x) {
		m_offset_x += x;
		if (m_auto_apply) {
			build_transform();
		}
	}

	void Camera::add_y(float y) {
		m_offset_y += y;
		if (m_auto_apply) {
			build_transform();
		}
	}

	void Camera::add_position(float x, float y) {
		m_offset_x += x;
		m_offset_y += y;
		if (m_auto_apply) {
			build_transform();
		}
	}

	void Camera::add_rotation(float rotation) {
		m_rotation += rotation;
		if (m_auto_apply) {
			build_transform();
		}
	}

	float Camera::get_zoom() const {
		return m_zoom;
	}

	float Camera::get_rotation() const {
		return m_rotation;
	}
	
	float Camera::get_x() const {
		return m_offset_x;
	}

	float Camera::get_y() const {
		return m_offset_y;
	}

	float Camera::get_width() const {
		if (m_width <= 0.0f) {
			throw SdeException{ "Camera bounds not set." };
		}
		return m_width;
	}

	float Camera::get_height() const {
		if (m_height <= 0.0f) {
			throw SdeException{ "Camera bounds not set." };
		}
		return m_height;
	}

	Rectangle<float> Camera::get_camera_rect() const {
		if (m_width <= 0.0f || m_height <= 0.0f) {
			throw SdeException{ "Camera bounds not set." };
		}
		return Rectangle<float>{ m_offset_x, m_offset_y, m_width, m_height };
	}
}