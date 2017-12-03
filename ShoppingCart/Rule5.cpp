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

DiscountInfo CRule5::CalculateDiscount(ArticleStorage const& articles, double total) const
{
	DiscountInfo discountInfo;

	size_t nArticles = articles.size();

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleC = GetArticle(articles, constants::ArticleId::C);

	nArticles -= articleA ? 1 : 0;
	nArticles -= articleC ? 1 : 0;

	if (nArticles == 3)
	{
		total -= articleA ? articleA->GetPrice() * articles.at(*articleA) : 0;
		total -= articleC ? articleC->GetPrice() * articles.at(*articleC) : 0;

		discountInfo.discount = total * discount;
	}

	return discountInfo;
}

}
}