#include "Messagebox.hpp"


namespace sde {
	Messagebox::Messagebox(const std::shared_ptr<Display>& display) {
		m_display = display;
	}

	Messagebox::Messagebox(const std::shared_ptr<Display>& display, const std::string& caption, const std::string& message) {
		m_display = display;
		m_caption = caption;
		m_message = message;
	}

	Messagebox::Messagebox(const std::shared_ptr<Display>& display, const std::string& caption, const std::string& message, const MessageButtons& buttons) {
		m_display = display;
		m_caption = caption;
		m_message = message;
		m_buttons = buttons;
	}

	void Messagebox::set_display(const std::shared_ptr<Display>& display) {
		m_display = display;
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

	const MessageReturn Messagebox::show() {
		m_result = al_show_native_message_box(m_display->get_display(), m_caption.c_str(), "", m_message.c_str(), "", static_cast<int>(m_buttons));
		return static_cast<MessageReturn>(m_result);
	}

	Messagebox::~Messagebox() {
	}
}
