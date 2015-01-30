//Harry Pham 79422112
#ifndef FWDSTRATEGY5_HPP
#define FWDSTRATEGY5_HPP
#include "FwdStrategy.hpp"

class FwdStrategy5 : public FwdStrategy
{
public:
	FwdStrategy5();
	virtual bool forward(Message &msg) const;
};

#endif //FWDSTRATEGY5_HPP