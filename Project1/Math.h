#ifndef _MATH_H_
#define _MATH_H_

#include <cmath>

#include "Vector2.h"
#include "Rectangle.h"
#include "Circle.h"


namespace sde {
	namespace math {
		template<typename T>
		static bool collision_rect_rect(const Rectangle<T>& rect_1, const Rectangle<T>& rect_2) {
			if ((rect_2.get_x() <= rect_1.get_x() + rect_1.get_width() || rect_2.get_x() + rect_2.get_width() >= rect_1.get_x()) &&
				(rect_2.get_y() <= rect_1.get_y() + rect_1.get_height() || rect_2.get_y() + rect_2.get_height() >= rect_1.get_y())) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_rect_rect(const T& rect_1_x, const T& rect_1_y, const T& rect_1_w, const T& rect_1_h, const T& rect_2_x, const T& rect_2_y, const T& rect_2_w, const T& rect_2_h) {
			if ((rect_2_x <= rect_1_x + rect_1_w || rect_2_x + rect_2_w >= rect_1_x) &&
				(rect_2_y <= rect_1_y + rect_1_h || rect_2_y + rect_2_h >= rect_1_y)) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_rect_vector(const Rectangle<T>& rect, const Vector2<T>& vector) {
			if ((vector.get_x() >= rect.get_x() && vector.get_x() <= rect.get_x() + rect.get_width()) &&
				(vector.get_y() >= rect.get_y() && vector.get_y() <= rect.get_y() + rect.get_height())) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_rect_vector(const T& rect_x, const T& rect_y, const T& rect_w, const T& rect_h, const T& vec_x, const T& vec_y) {
			if ((vec_x >= rect_x && vec_x <= rect_x + rect_w) &&
				(vec_y >= rect_y && vec_y <= rect_y + rect_h)) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_circle_vector(const Circle<T>& circle, const Vector2<T>& vector) {
			if (circle.get_radius() > static_cast<T>(std::sqrt(std::pow(std::abs(vector.get_x() - circle.get_x()), 2.0f) + std::pow(std::abs(vector.get_y() - circle.get_y()), 2.0f)))) {
				return true;
			}
			return false;
		}

		template<typename T>
		static bool collision_circle_vector(const T& center_x, const T& center_y, const T& radius, const T& vec_x, const T& vec_y) {
			if (radius > static_cast<T>(std::sqrt(std::pow(std::abs(vec_x - center_x), 2.0f) + std::pow(std::abs(vec_y - center_y), 2.0f)))) {
				return true;
			}
			return false;
		}
	}
}

#endif