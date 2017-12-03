#include "stdafx.h"
#include "Rule6.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.1;

}

DiscountInfo CRule6::CalculateDiscount(ArticleStorage const& articles, double total) const
{
	DiscountInfo discountInfo;

	size_t nArticles = articles.size();

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleC = GetArticle(articles, constants::ArticleId::C);

	nArticles -= articleA ? 1 : 0;
	nArticles -= articleC ? 1 : 0;

	if (nArticles == 4)
	{
		discountInfo.discount = total * discount;
	}

	return discountInfo;
}

}
}