#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// 3 articles rule
class CRule5
	: public ARule
{
public:
	DiscountInfo CalculateDiscount(ArticleStorage const& articles, double total) const final;

};

}
}