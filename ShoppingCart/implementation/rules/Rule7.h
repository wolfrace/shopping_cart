#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// 5 articles rule
class CRule7
	: public ARule
{
public:
	DiscountInfo CalculateDiscount(ArticleStorage const& articles, double total) const final;

};

}
}