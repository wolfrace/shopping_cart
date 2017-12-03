#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// D & E rule
class CRule2
	: public ARule
{
public:
	double GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}