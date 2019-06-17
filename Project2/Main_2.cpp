#include <sd_engine.hpp>


int main() {
	sde::Core core{ "sde window", 1024, 768 };

	sde::Renderer renderer{ };
	
	sde::Assets assets{ core.get_assets() };
	//assets.load_texture("level_0", "res/level_0.tga");
	//assets.load_texture("level_1", "res/level_1.tga");
	//assets.load_texture("level_2", "res/level_2.tga");
	//assets.load_texture("level_3", "res/level_3.tga");

	assets.load_texture_sheet("sheet", "res/sheet.tga", 64, 64);

	//sde::Parallax parallax_back{ };
	//parallax_back.add_parallax_sprite(0, 0.0f, 0.0f, 1.0f, 0.0f, assets.get_texture("level_0"));
	//parallax_back.add_parallax_sprite(1, 0.0f, 128.0f, 2.0f, 0.0f, assets.get_texture("level_1"));
	//parallax_back.add_parallax_sprite(2, 0.0f, 384.0f, 4.0f, 0.0f, assets.get_texture("level_2"));
	//parallax_back.add_parallax_sprite(3, 0.0f, 512.0f, 8.0f, 0.0f, assets.get_texture("level_3"));
	
	sde::Animation animation{ 4, assets.get_texture_sheet("sheet") };
	
	//core.add_updateable(&parallax_back);
	core.add_updateable(&animation);

	while (core.is_running()) {
		core.update();

		if (core.poll_events_timed()) {
			if (core.get_event_type() == sde::Event::EVENT_KEYDOWN && core.get_keycode() == sde::Keycode::KEYCODE_ESCAPE) {
				core.close();
			}
		}
		renderer.clear(0, 0, 0);

		//renderer.draw_object(parallax_back);
		renderer.draw_object(animation);

		renderer.display();
	}

	return SDE_SUCCESS;
}