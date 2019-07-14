#ifndef _MESSAGEBOX_HPP_
#define _MESSAGEBOX_HPP_

#include <allegro5/allegro_native_dialog.h>

#include <string>

#include "Display.hpp"
#include "MessageButtons.hpp"
#include "MessageReturn.hpp"


namespace sde {
	class Messagebox {
		private:
			std::shared_ptr<Display> m_display{ nullptr };
			std::string m_message{ };
			std::string m_caption{ };
			MessageButtons m_buttons{ MessageButtons::MSGBOX_OK_CANCEL };
			MessageReturn m_result{ MessageReturn::MSGBOX_RET_NULL };


		public:
			Messagebox() = default;
			explicit Messagebox(const Display& display);
			Messagebox(const Display& display, const std::string& caption, const std::string& message);
			Messagebox(const Display& display, const std::string& caption, const std::string& message, const MessageButtons& buttons);
			~Messagebox() = default;

			void set_display(const Display& display);
			void set_message(const std::string& message);
			void set_caption(const std::string& caption);
			void set_message_type(const MessageButtons& buttons);

			const MessageReturn& show();
	};
}

#endif