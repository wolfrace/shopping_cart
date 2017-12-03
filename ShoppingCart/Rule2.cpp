#include "stdafx.h"
#include "Rule2.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.05;

}

DiscountInfo CRule2::CalculateDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double /*total*/) const
{
	DiscountInfo discountInfo;

	auto articleD = GetArticle(articles, constants::ArticleId::D);
	auto articleE = GetArticle(articles, constants::ArticleId::E);

	if (articleD != nullptr && articleE != nullptr)
	{
		size_t nPair = std::min(articles.at(articleD), articles.at(articleE));

		discountInfo.discount += articleD->GetPrice() * nPair * discount;
		discountInfo.discount += articleE->GetPrice() * nPair * discount;

		discountInfo.discountedArticles[articleD] = nPair;
		discountInfo.discountedArticles[articleE] = nPair;
	}

	return discountInfo;
}

}
}