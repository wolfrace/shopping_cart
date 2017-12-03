#pragma once
#include "Article.h"

namespace store
{

struct DiscountInfo
{
	double discount = 0.;
	ArticleStorage discountedArticles;
};

class IRule
{
public:
	virtual ~IRule() = default;

	virtual DiscountInfo CalculateDiscount(ArticleStorage const& articles, double total) const = 0;
};

using IRuleUniquePtr = std::unique_ptr<IRule>;

}