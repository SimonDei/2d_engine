#ifndef _MESSAGEBOX_HPP_
#define _MESSAGEBOX_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include <string>

#include "Display.hpp"
#include "MessageButtons.hpp"
#include "MessageReturn.hpp"


namespace sde {
	class Messagebox {
		private:
			std::shared_ptr<Display> m_display;
			std::string m_message = "";
			std::string m_caption = "";
			MessageButtons m_buttons = MessageButtons::MSGBOX_OK_CANCEL;
			int m_result = 0;


		public:
			Messagebox() = default;
			explicit Messagebox(const std::shared_ptr<Display>& display);
			Messagebox(const std::shared_ptr<Display>& display, const std::string& caption, const std::string& message);
			Messagebox(const std::shared_ptr<Display>& display, const std::string& caption, const std::string& message, const MessageButtons& buttons);
			~Messagebox();

			void set_display(const std::shared_ptr<Display>& display);
			void set_message(const std::string& message);
			void set_caption(const std::string& caption);
			void set_message_type(const MessageButtons& buttons);

			const MessageReturn& show();
	};
}

#endif