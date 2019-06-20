#include <sd_engine.hpp>


int main() {
	sde::Core core{ "sde window", 1024, 768 };

	sde::Renderer renderer{ };

	sde::Assets assets{ core.get_assets() };
	assets.load_texture("level_1", "res/level_3.tga");

	sde::Textbox textb{ assets.get_texture("level_1") };

	while (core.is_running()) {
		if (core.poll_events_timed()) {
			if (core.get_event_type() == sde::Event::EVENT_KEYDOWN) {
				switch (core.get_keycode()) {
					case sde::Keycode::KEYCODE_ESCAPE:
						core.close();
						break;
				}

			}
		}
		renderer.clear(0, 0, 0);

		
		
		renderer.display();
	}

	return SDE_SUCCESS;
}