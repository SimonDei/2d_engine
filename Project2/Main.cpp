#include <sd_engine.hpp>


int main() {
	sde::Core core;
	core.set_window_position(50, 50);
	core.set_window_title("sde window");
	core.create_window(1024, 768);

	sde::Renderer renderer;

	sde::Assets assets(core.get_assets());
	assets.load_music("music", "res/music.ogg");
	assets.load_texture("tex", "res/test.jpg");

	sde::Sprite spr(assets.get_texture("tex"));
	spr.set_position(50.0f, 50.0f);	

	sde::MusicQueue queue;
	queue.push_music(assets.get_music("music"));
	queue.play();

	queue.set_volume(200.0f);

	core.add_updateable(queue);

	while (core.is_running()) {
		while (core.is_event_in_queue()) {
			if (core.get_event_type() == sde::Event::EVENT_KEYDOWN && core.get_keycode() == sde::Keycode::KEYCODE_ESCAPE) { core.close(); }
		}
		renderer.clear(255, 0, 0);

		renderer.draw_sprite(spr);

		renderer.display();
	}

	return 0;
}