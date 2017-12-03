#include "stdafx.h"
#include "ShoppingCart.h"

namespace store
{
namespace impl
{

CShoppingCart::CShoppingCart(std::vector<IRuleUniquePtr> && rules)
	: m_rules(std::move(rules))
{
}

void store::impl::CShoppingCart::AddArticle(IArticleSharedPtr const& article)
{
	m_articles.emplace_back(article);
}

double store::impl::CShoppingCart::CalculateCost() const
{
	throw std::logic_error("The method or operation is not implemented.");
}



}
}