#include <sd_engine.hpp>


void init() {
	std::cout << "here" << std::endl;
}

void keyboard() {

}

void update() {

}

void render() {

}

int main2() {
	sde::Core core{ "sde window", 1024, 768 };
	core.set_keyboard_function(std::function<void()>(keyboard));
	core.set_update_function(std::function<void()>(update));
	core.set_render_function(std::function<void()>(render));

	sde::Renderer renderer{ };

	sde::Assets assets{ core.get_assets() };
	assets.load_texture("level_1", "res/level_3.tga");
	assets.load_font("arial", "res/arial.ttf");

	sde::Textbox textb{ assets.get_texture("level_1"), assets.get_font("arial") };
	textb.set_position(50.0f, 50.0f);
	textb.set_size(200.0f, 75.0f);
	//textb.set_max_size(10);

	while (core.is_running()) {
		if (core.poll_events_timed()) {
			if (core.get_event_type() == sde::Event::EVENT_KEYDOWN) {	
				switch (core.get_keycode()) {
					case sde::Keycode::KEYCODE_ESCAPE:
						core.close();
						break;
				}
				textb.add_key(core.get_keycode());
			}
		}
		textb.check_focus();

		renderer.clear(0x000000);

		renderer.draw_object(textb);

		renderer.display();
	}

	return SDE_SUCCESS;
}