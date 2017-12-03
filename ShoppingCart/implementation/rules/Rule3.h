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
	DiscountInfo CalculateDiscount(ArticleStorage const& articles, double total) const final;

};

}
}