#pragma once
#include "IArticle.h"

namespace store
{

struct DiscountInfo
{
	double discount;
	std::map<IArticleSharedPtr, size_t /*count*/> discountedArticles;
};

class IRule
{
public:
	virtual ~IRule() = default;

	virtual DiscountInfo CalculateDiscount(std::map<IArticleSharedPtr, size_t /*count*/> const& articles, double total) const = 0;
};

using IRuleUniquePtr = std::unique_ptr<IRule>;

}