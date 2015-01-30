//Harry Pham 79422112
#include "FwdStrategy2.hpp"

FwdStrategy2::FwdStrategy2(unsigned int t)
:type(t)
{
}

bool FwdStrategy2::forward(Message &msg) const
{
	if (msg.get_message_content().get_type() == type)
	{
		return true;
	}
	return false;
}