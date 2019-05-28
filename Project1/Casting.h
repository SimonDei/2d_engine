#pragma once

constexpr unsigned int SDE_SUCCESS = 0;
constexpr unsigned int SDE_FAILURE = -1;

#define sde_cast(end_type, value) static_cast<end_type>(value)
#define sde_ref_to_ptr(end_type, ini_type) const_cast<end_type*>(&ini_type)
#define sde_get_bitmap(value) value.get_texture().get_texture()
#define sde_share(type, value) std::make_shared<type>(value)