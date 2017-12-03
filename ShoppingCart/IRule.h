#pragma once
#include "IArticle.h"

namespace store
{

class IRule
{
public:
	virtual ~IRule() = default;

	virtual double GetDiscount(std::map<IArticleSharedPtr, size_t /*count*/> const& articles, double total) const = 0;
};

using IRuleUniquePtr = std::unique_ptr<IRule>;

}