#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// E & F & G rule
class CRule3
	: public ARule
{
public:
	double GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}