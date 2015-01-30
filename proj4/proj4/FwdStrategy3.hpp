//Harry Pham 79422112
#ifndef FWDSTRATEGY3_HPP
#define FWDSTRATEGY3_HPP
#include "FwdStrategy.hpp"

class FwdStrategy3 : public FwdStrategy
{
public:
	explicit FwdStrategy3(unsigned int q);
	virtual bool forward(Message &msg) const;
private:
	unsigned int quality;
};

#endif //FWDSTRATEGY3_HPP