#pragma once


namespace sde {
	enum class MessageButtons : int {
		MSGBOX_WARNING = 1,
		MSGBOX_ERROR = 2,
		MSGBOX_OK_CANCEL = 4,
		MSGBOX_YES_NO = 8,
		MSGBOX_QUESTION = 16
	};
}