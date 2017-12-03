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
	DiscountInfo CalculateDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}