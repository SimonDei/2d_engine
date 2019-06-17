#include <sd_engine.hpp>


int main() {
	sde::Core core{ "sde window", 1024, 768 };

	sde::Renderer renderer{ };
	
	sde::Assets assets{ core.get_assets() };
	assets.load_texture("level_0", "res/level_2.tga");
	assets.load_texture("level_1", "res/level_3.tga");

	sde::Button button{ assets.get_texture("level_0"), assets.get_texture("level_1"), 50.0f, 50.0f, 200.0f, 75.0f };
	button.set_handle_function([]() { 
		std::cout << "hello" << std::endl;	
	});

	while (core.is_running()) {
		if (core.poll_events_timed()) {
			if (core.get_event_type() == sde::Event::EVENT_KEYDOWN && core.get_keycode() == sde::Keycode::KEYCODE_ESCAPE) {
				core.close();
			}
		}
		button.is_pressed_and_handle();

		renderer.clear(0, 0, 0);

		button.draw();
		
		renderer.display();
	}

	return SDE_SUCCESS;
}