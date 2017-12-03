#pragma once
#include "IShoppingCart.h"
#include "IRule.h"

namespace store
{
namespace impl
{

class CShoppingCart
	: public IShoppingCart
{
public:
	CShoppingCart(std::vector<IRuleUniquePtr> && rules);

	void AddArticle(IArticleSharedPtr const& article) final;
	double CalculateCost() const final;

private:
	double GetTotal(std::map<IArticleSharedPtr, size_t> const& articles) const;

private:
	std::vector<IRuleUniquePtr> m_rules;
	std::map<IArticleSharedPtr, size_t> m_articles;
};

}
}