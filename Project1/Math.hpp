#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <cmath>

#include "Vector2.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"


namespace sde {
	namespace math {
		template<typename T>
		static bool collision_rect_rect(const Rectangle<T>& rect_1, const Rectangle<T>& rect_2) {
			if (rect_1.get_x()						 < rect_2.get_x() + rect_2.get_width() &&
				rect_1.get_x() + rect_1.get_width()  > rect_2.get_x() &&
				rect_1.get_y()						 < rect_2.get_y() + rect_2.get_height() &&
				rect_1.get_y() + rect_1.get_height() > rect_2.get_y()) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_rect_rect(const T& rect_1_x, const T& rect_1_y, const T& rect_1_w, const T& rect_1_h, const T& rect_2_x, const T& rect_2_y, const T& rect_2_w, const T& rect_2_h) {
			if (rect_1_x			< rect_2_x + rect_2_w &&
				rect_1_x + rect_1_w > rect_2_x &&
				rect_1_y			< rect_2_y + rect_2_h &&
				rect_1_y + rect_1_h > rect_2_y) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_rect_vec(const Rectangle<T>& rect, const Vector2<T>& vector) {
			if (vector.get_x() >= rect.get_x() &&
				vector.get_x() <= rect.get_x() + rect.get_width() &&
				vector.get_y() >= rect.get_y() &&
				vector.get_y() <= rect.get_y() + rect.get_height()) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_rect_vec(const T& rect_x, const T& rect_y, const T& rect_w, const T& rect_h, const T& vec_x, const T& vec_y) {
			if (vec_x >= rect_x &&
				vec_x <= rect_x + rect_w &&
				vec_y >= rect_y &&
				vec_y <= rect_y + rect_h) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_circle_rect(const Circle<T>& circle, const Rectangle<T>& rect) {
			T test_x = circle.get_x();
			T test_y = circle.get_y();
			if (circle.get_x() < rect.get_x()) {
				test_x = rect.get_x();
			} else if (circle.get_x() > rect.get_x() + rect.get_width()) {
				test_x = rect.get_x() + rect.get_width();
			}
			if (circle.get_y() < rect.get_y()) {
				test_y = rect.get_y();
			} else if (circle.get_y() > rect.get_y() + rect.get_height()) {
				test_y = rect.get_y() + rect.get_height();
			}
			T dist_x = circle.get_x() - test_x;
			T dist_y = circle.get_y() - test_y;
			T distance = static_cast<T>(std::sqrt(std::pow(dist_x, 2) + std::pow(dist_y, 2)));
			if (distance <= circle.get_radius()) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_circle_rect(const T& center_x, const T& center_y, const T& radius, const T& rect_x, const T& rect_y, const T& rect_w, const T& rect_h) {
			T test_x = center_x;
			T test_y = center_y;
			if (center_x < rect_x) {
				test_x = rect_x;
			} else if (center_x > rect_x + rect_w) {
				test_x = rect_x + rect_w;
			}
			if (center_y < rect_y) {
				test_y = rect_y;
			} else if (center_y > rect_y + rect_h) {
				test_y = rect_y + rect_h;
			}
			T dist_x = center_x - test_x;
			T dist_y = center_y - test_y;
			T distance = static_cast<T>(std::sqrt(std::pow(dist_x, 2) + std::pow(dist_y, 2)));
			if (distance <= radius) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_circle_vec(const Circle<T>& circle, const Vector2<T>& vector) {
			if (circle.get_radius() > static_cast<T>(std::sqrt(std::pow(std::abs(vector.get_x() - circle.get_x()), 2) + std::pow(std::abs(vector.get_y() - circle.get_y()), 2)))) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_circle_vec(const T& center_x, const T& center_y, const T& radius, const T& vec_x, const T& vec_y) {
			if (radius > static_cast<T>(std::sqrt(std::pow(std::abs(vec_x - center_x), 2) + std::pow(std::abs(vec_y - center_y), 2)))) {
				return true;
			}
			return false;
		}
	}
}

#endif