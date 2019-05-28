#pragma once

#include <string>


namespace sde {
	class SubTexture {
		private:
			std::string m_region_desc = "";
			float m_width = 0.0f;
			float m_height = 0.0f;
			float m_region_x = 0.0f;
			float m_region_y = 0.0f;


		public:
			SubTexture() = default;
			SubTexture();
			~SubTexture();

			const std::string& get_sub_texture_name() const;
	};
}
