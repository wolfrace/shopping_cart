#pragma once
#include "ICart.h"

namespace store
{

class CCartFactory
{
public:
	static ICartUniquePtr CreateCart();
};

}