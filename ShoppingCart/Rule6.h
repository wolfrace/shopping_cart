#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// 4 articles rule
class CRule6
	: public ARule
{
public:
	DiscountInfo CalculateDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}