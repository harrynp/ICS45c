//Harry Pham 79422112
#ifndef FWDSTRATEGY2_HPP
#define FWDSTRATEGY2_HPP
#include "FwdStrategy.hpp"

class FwdStrategy2 : public FwdStrategy
{
public:
	explicit FwdStrategy2(unsigned int t);
	virtual bool forward(Message &msg) const;
private:
	unsigned int type;
};

#endif //FWDSTRATEGY2_HPP