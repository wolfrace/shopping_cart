#include "stdafx.h"
#include "Rule5.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.05;

}

DiscountInfo CRule5::CalculateDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const
{
	DiscountInfo discountInfo;

	size_t nArticles = articles.size();

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleC = GetArticle(articles, constants::ArticleId::C);

	nArticles -= articleA != nullptr ? 1 : 0;
	nArticles -= articleC != nullptr ? 1 : 0;

	if (nArticles == 3)
	{
		discountInfo.discount = total * discount;
	}

	return discountInfo;
}

}
}