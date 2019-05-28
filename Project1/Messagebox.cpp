#include "Messagebox.h"


namespace sde {
	Messagebox::Messagebox(const Display& display) {
		m_display = sde_ref_to_ptr(Display, display);
	}

	Messagebox::Messagebox(const Display& display, const std::string& caption, const std::string& message) {
		m_display = sde_ref_to_ptr(Display, display);
		m_caption = caption;
		m_message = message;
	}

	Messagebox::Messagebox(const Display& display, const std::string& caption, const std::string& message, const MessageButtons& buttons) {
		m_display = sde_ref_to_ptr(Display, display);
		m_caption = caption;
		m_message = message;
		m_buttons = buttons;
	}

	void Messagebox::set_display(const Display& display) {
		m_display = sde_ref_to_ptr(Display, display);
	}

	void Messagebox::set_message(const std::string& message) {
		m_message = message;
	}

	void Messagebox::set_caption(const std::string& caption) {
		m_caption = caption;
	}

	void Messagebox::set_message_type(const MessageButtons& buttons) {
		m_buttons = buttons;
	}

	const MessageReturn& Messagebox::show() {
		m_result = al_show_native_message_box(m_display->get_display(), m_caption.c_str(), "", m_message.c_str(), "", sde_cast(int, m_buttons));
		return sde_cast(MessageReturn, m_result);
	}

	Messagebox::~Messagebox() {
	}
}
