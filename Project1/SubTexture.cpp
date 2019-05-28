#include "SubTexture.h"


namespace sde {
	const std::string& SubTexture::get_sub_texture_name() const {
		return m_region_desc;
	}

	SubTexture::~SubTexture() {
	}
}