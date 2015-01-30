//Harry Pham 79422112
#include "FwdStrategy3.hpp"

FwdStrategy3::FwdStrategy3(unsigned int q)
:quality(q)
{
}

bool FwdStrategy3::forward(Message &msg) const
{
	if (msg.get_message_content().get_quality() >= quality)
	{
		return true;
	}
	return false;
}