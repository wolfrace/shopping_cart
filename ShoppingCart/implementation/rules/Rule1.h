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
	DiscountInfo CalculateDiscount(ArticleStorage const& articles, double total) const final;
};

}
}