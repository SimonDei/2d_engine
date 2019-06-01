#pragma once

#include <string>
#include <unordered_map>

#include "Component.h"


namespace sde {
	class Entity {
		private:
			std::unordered_map<std::string, Component> m_components;
			unsigned int m_id = 0;


		public:
			Entity() = default;
			~Entity() { };

			virtual void add_component(const Component& component) {
				m_components.insert(std::make_pair(std::string(typeid(component).name()), component));
			};
	};
}
