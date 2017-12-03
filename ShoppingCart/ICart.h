#pragma once
#include "Article.h"

namespace store
{

class ICart
{
public:
	virtual ~ICart() = default;

	virtual void AddArticle(IArticleSharedPtr const& article) = 0;

	virtual double CalculateCost() const = 0;
	
};

using ICartUniquePtr = std::shared_ptr<ICart>;

}