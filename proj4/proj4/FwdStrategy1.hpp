//Harry Pham 79422112
#ifndef FWDSTRATEGY1_HPP
#define FWDSTRATEGY1_HPP
#include "FwdStrategy.hpp"

class FwdStrategy1 : public FwdStrategy
{
public:
	FwdStrategy1();
	virtual bool forward(Message &msg) const;
};

#endif //FWDSTRATEGY1_HPP