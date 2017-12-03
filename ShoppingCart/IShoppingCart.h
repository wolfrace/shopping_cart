#pragma once
#include "IArticle.h"

namespace store
{

class IShoppingCart
{
public:
	virtual ~IShoppingCart() = default;

	virtual void AddArticle(IArticleSharedPtr const& article) = 0;

	virtual double CalculateCost() const = 0;
	
};

}