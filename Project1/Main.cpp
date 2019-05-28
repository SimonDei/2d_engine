// ^(?([^\r\n])\s)*[^\s+?/]+[^\n]*$

#include "Core.h"
#include "Logger.h"
#include "Renderer.h"
#include "Assets.h"
#include "Sprite.h"
#include "Music.h"
#include "MusicQueue.h"
#include "TextureSheet.h"


int main() {
	sde::logger::set_debug_enable(true);

	sde::Core core("test app", 1024, 768);

	sde::Renderer renderer;
	renderer.set_thickness(5.0f);

	sde::Assets assets;
	assets.load_texture("test", "res/test.jpg");
	assets.load_music("test1", "res/music.ogg");
	assets.load_music("test2", "res/music2.ogg");
	assets.load_texture_sheet("sheet1", "res/sheet.png", 32, 32);
	core.add_disposable(sde_share(sde::Assets, assets));

	sde::Sprite sprite(assets.get_texture("test"), 50.0f, 50.0f, 90.0f);

	sde::MusicQueue musQueue;
	musQueue.push_music(assets.get_music("test1"));
	musQueue.push_music(assets.get_music("test2"));
	core.add_updateable(musQueue);

	musQueue.play();

	while (core.is_running()) {
		if (core.is_event_in_queue()) {
			switch(core.get_event_type()) {
				case sde::EVENT_KEYDOWN:
					if (core.get_keycode() == sde::KEYCODE_ESCAPE) { core.close(); }
					if (core.get_keycode() == sde::KEYCODE_Q) {
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
		core.update();
		renderer.clear(255, 0, 0);

		renderer.draw_circle(250, 250, 100, sde::Color3<unsigned char>(80, 80, 80));

		renderer.display();
	}

	return SDE_SUCCESS;
}
