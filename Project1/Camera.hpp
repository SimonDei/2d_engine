#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include <allegro5/allegro.h>

#include "Rectangle.hpp"
#include "SdeException.hpp"


namespace sde {
	class Camera {
		private:
			ALLEGRO_TRANSFORM m_identity{ };
			ALLEGRO_TRANSFORM m_transform{ };
			float m_offset_x{ 0.0f };
			float m_offset_y{ 0.0f };
			float m_rotation{ 0.0f };
			float m_zoom{ 1.0f };
			float m_width{ 0.0f };
			float m_height{ 0.0f };
			bool m_auto_apply{ false };

			inline void build_transform() {
				al_build_transform(&m_transform, m_offset_x, m_offset_y, m_zoom, m_zoom, m_rotation);
				al_use_transform(&m_transform);
			}


		public:
			Camera();
			~Camera();

			void apply();
			void reset();

			void set_camera_bounds(float width, float height);
			void set_auto_apply(bool enabled);

			void set_offset_x(float x);
			void set_offset_y(float y);

			/**
			  * Sets the zoom for the 2D camera.
			  * A value greater than 1.0 zooms in, a value less than 1.0 zooms out.
			  * @param zoom - the new value for the camera zoom.
			**/
			void set_zoom(float zoom);
						
			void add_rotation(float rotation);

			void add_offset_x(float x);
			void add_offset_y(float y);
			void add_offset(float x, float y);

			float get_zoom() const;
			float get_rotation() const;

			float get_offset_x() const;
			float get_offset_y() const;
	
			const Rectangle<float> get_camera_rect() const;
	};
}

#endif