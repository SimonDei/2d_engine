#ifndef _TEXTUREFLAGS_HPP_
#define _TEXTUREFLAGS_HPP_


namespace sde {
	enum class TextureFlags : int {
		VIDEO_BITMAP = 1024,
		MEMORY_BITMAP = 1,
		NO_PRESERVE = 8,
		MIN_LINEAR = 64,
		MAG_LINEAR = 128,
		MIPMAP = 256
	};
}

#endif