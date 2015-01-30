//Harry Pham 79422112
#ifndef FWDSTRATEGY4_HPP
#define FWDSTRATEGY4_HPP
#include "FwdStrategy.hpp"

class FwdStrategy4 : public FwdStrategy
{
public:
	FwdStrategy4(unsigned int t, unsigned int q);
	virtual bool forward(Message &msg) const;
private:
	unsigned int type;
	unsigned int quality;
};

#endif //FWDSTRATEGY4_HPP