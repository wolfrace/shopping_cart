#pragma once
#include "IArticle.h"

namespace store
{

class IRule
{
public:
	virtual ~IRule() = default;

	virtual double GetDiscount(std::vector<IArticleSharedPtr> const& articles) const = 0;
};

using IRuleUniquePtr = std::unique_ptr<IRule>;

}