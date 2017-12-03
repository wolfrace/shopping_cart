#include "stdafx.h"
#include "Rule3.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.05;

}

DiscountInfo CRule3::CalculateDiscount(ArticleStorage const& articles, double /*total*/) const
{
	DiscountInfo discountInfo;

	auto articleE = GetArticle(articles, constants::ArticleId::E);
	auto articleF = GetArticle(articles, constants::ArticleId::F);
	auto articleG = GetArticle(articles, constants::ArticleId::G);

	if (articleE && articleF && articleG)
	{
		size_t nPair = std::min(std::min(articles.at(*articleE), articles.at(*articleF)), articles.at(*articleG));

		discountInfo.discount += articleE->GetPrice() * nPair * discount;
		discountInfo.discount += articleF->GetPrice() * nPair * discount;
		discountInfo.discount += articleG->GetPrice() * nPair * discount;

		discountInfo.discountedArticles[*articleE] = nPair;
		discountInfo.discountedArticles[*articleF] = nPair;
		discountInfo.discountedArticles[*articleG] = nPair;
	}

	return discountInfo;
}

}
}