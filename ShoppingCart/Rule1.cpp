#include "stdafx.h"
#include "Rule1.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.1;

}

DiscountInfo CRule1::CalculateDiscount(ArticleStorage const& articles, double /*total*/) const
{
	DiscountInfo discountInfo;

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleB = GetArticle(articles, constants::ArticleId::B);

	if (articleA && articleB)
	{
		size_t nPair = std::min(articles.at(*articleA), articles.at(*articleB));

		discountInfo.discount += articleA->GetPrice() * nPair * discount;
		discountInfo.discount += articleB->GetPrice() * nPair * discount;

		discountInfo.discountedArticles[*articleA] = nPair;
		discountInfo.discountedArticles[*articleB] = nPair;
	}

	return discountInfo;
}

}
}