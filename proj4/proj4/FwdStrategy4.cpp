//Harry Pham 79422112
#include "FwdStrategy4.hpp"

FwdStrategy4::FwdStrategy4(unsigned int t, unsigned int q)
:type(t), quality(q)
{
}

bool FwdStrategy4::forward(Message &msg) const
{
	if (msg.get_message_content().get_type() == type && msg.get_message_content().get_quality() >= quality)
	{
		return true;
	}
	return false;
}