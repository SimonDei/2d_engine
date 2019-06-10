#ifndef _MESSAGERETURN_HPP_
#define _MESSAGERETURN_HPP_


namespace sde {
	enum class MessageReturn : int {
		MSGBOX_RET_NULL = 0,
		MSGBOX_RET_OK = 1,
		MSGBOX_RET_CANCEL = 2
	};
}

#endif