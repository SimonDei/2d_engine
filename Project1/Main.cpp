// ^(?([^\r\n])\s)*[^\s+?/]+[^\n]*$

#include "Core.h"
#include "Logger.h"
#include "Renderer.h"
#include "Assets.h"
#include "Sprite.h"
#include "MusicQueue.h"
#include "Math.h"


int main() {
	sde::logger::set_debug_enable(true);

	sde::Core core;
	core.set_window_title("sde engine test");
	core.set_window_position(50, 50);
	core.create_window(1024, 768);

	sde::Renderer renderer;
	renderer.set_thickness(5.0f);

	core.get_assets().load_texture("test", "res/test.jpg");
	core.get_assets().load_texture("test", "res/test.jpg");
	core.get_assets().load_music("test1", "res/music.ogg");
	core.get_assets().load_music("test2", "res/music2.ogg");
	core.get_assets().load_texture_sheet("sheet1", "res/sheet.jpg");

	/*
	bool rect_check = sde::math::collision_rect_rect(sde::Rectangle<int>(50, 50, 50, 50), sde::Rectangle<int>(25, 25, 100, 100));
	bool rect_vec = sde::math::collision_rect_vector(50, 50, 100, 100, 60, 60);
	bool circ_vec = sde::math::collision_circle_vector(50, 50, 50, 50, 50);
	*/

	sde::Sprite sprite(core.get_assets().get_texture_sheet("sheet1").get_texture_rect(75, 25, 25, 25), 50.0f, 50.0f, 90.0f);

	sde::MusicQueue musQueue;
	musQueue.push_music(core.get_assets().get_music("test1"));
	musQueue.push_music(core.get_assets().get_music("test2"));
	core.add_updateable(musQueue);
	
	musQueue.play();

	while (core.is_running()) {
		core.update();
		if (core.is_event_in_queue()) {
			switch(core.get_event_type()) {
				case sde::Event::EVENT_KEYDOWN:
					if (core.get_keycode() == sde::Keycode::KEYCODE_Q) {
						sde::logger::debug_log("q key pressed!");
						if (musQueue.is_playing()) {
							musQueue.pause();
						} else {
							musQueue.resume();
						}
					}
					break;
			}
		}
		renderer.clear(255, 0, 0);

		renderer.draw_circle(250, 250, 100, 80, 80, 80);
		renderer.draw_sprite(sprite);

		renderer.display();
	}

	return SDE_SUCCESS;
}
