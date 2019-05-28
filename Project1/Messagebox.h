#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include <string>

#include "Display.h"
#include "MessageButtons.h"
#include "MessageReturn.h"


namespace sde {
	class Messagebox {
		private:
			Display* m_display;
			std::string m_message = "";
			std::string m_caption = "";
			MessageButtons m_buttons = sde::MSGBOX_OK_CANCEL;
			int m_result = 0;


		public:
			Messagebox() = default;
			explicit Messagebox(const Display& display);
			Messagebox(const Display& display, const std::string& caption, const std::string& message);
			Messagebox(const Display& display, const std::string& caption, const std::string& message, const MessageButtons& buttons);
			~Messagebox();

			void set_display(const Display& display);
			void set_message(const std::string& message);
			void set_caption(const std::string& caption);
			void set_message_type(const MessageButtons& buttons);

			const MessageReturn& show();
	};
}
