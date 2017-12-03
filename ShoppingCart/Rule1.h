#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// A & B rule
class CRule1
	: public ARule
{
public:
	double GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}