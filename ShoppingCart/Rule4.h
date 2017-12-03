#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// A & [K, L, M] rule
class CRule4
	: public ARule
{
public:
	double GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}