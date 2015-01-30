//Harry Pham 79422112
#ifndef FWDSTRATEGY_HPP
#define FWDSTRATEGY_HPP
#include "Message.hpp"

class FwdStrategy
{
public:
	virtual ~FwdStrategy() = default;
	virtual bool forward(Message &msg) const = 0;
};

#endif //FWDSTRATEGY_HPP