#include "stdafx.h"
#include "Cart.h"

namespace store
{
namespace impl
{

namespace
{

void EraseArticles(ArticleStorage & articles, ArticleStorage const& erasable)
{
	for (auto& pair: erasable)
	{
		articles.at(pair.first) -= pair.second;
	}
}

}

CCart::CCart(std::vector<IRuleUniquePtr> && rules)
	: m_rules(std::move(rules))
{
}

double CCart::GetTotal(ArticleStorage const& articles) const
{
	auto total = std::accumulate(articles.cbegin(), articles.cend(), 0., [](auto value, auto const& elem) {
		return value + elem.second * elem.first.GetPrice();
	});

	return total;
}

void store::impl::CCart::AddArticle(CArticle const& article)
{
	m_articles[article] += 1;
}

double store::impl::CCart::CalculateCost() const
{
	auto totalCost = GetTotal(m_articles);

	auto notDiscountedArticles = m_articles;
	for (auto& rule: m_rules)
	{
		const auto total = GetTotal(notDiscountedArticles);
		auto discountInfo = rule->CalculateDiscount(m_articles, total);

		if (discountInfo.discount > 0)
		{
			totalCost -= discountInfo.discount;
			EraseArticles(notDiscountedArticles, discountInfo.discountedArticles);
		}
	}

	assert(totalCost > 0);

	return totalCost;
}

}
}