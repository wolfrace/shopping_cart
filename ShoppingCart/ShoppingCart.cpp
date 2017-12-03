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

double CShoppingCart::GetTotal(std::map<IArticleSharedPtr, size_t> const& articles) const
{
	auto total = std::accumulate(articles.cbegin(), articles.cend(), 0., [](auto value, auto const& elem) {
		return value + elem.second * elem.first->GetPrice();
	});

	return total;
}

void store::impl::CShoppingCart::AddArticle(IArticleSharedPtr const& article)
{
	m_articles[article] += 1;
}

double store::impl::CShoppingCart::CalculateCost() const
{
	auto total = GetTotal(m_articles);

	for (auto& rule: m_rules)
	{
		auto discount = rule->GetDiscount(m_articles, total);
		assert(discount <= total);

		if (discount > 0)
		{
			total -= discount;
			break; // rule is activated
		}
	}

	return total;
}

}
}