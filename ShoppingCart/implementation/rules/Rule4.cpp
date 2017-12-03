#include "stdafx.h"
#include "Rule4.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.05;

}

DiscountInfo CRule4::CalculateDiscount(ArticleStorage const& articles, double /*total*/) const
{
	DiscountInfo discountInfo;

	auto articleA = GetArticle(articles, constants::ArticleId::A);

	auto articleK = GetArticle(articles, constants::ArticleId::K);
	auto articleL = GetArticle(articles, constants::ArticleId::L);
	auto articleM = GetArticle(articles, constants::ArticleId::M);

	if (articleA && 
		(articleK || articleL || articleM))
	{
		discountInfo.discountedArticles[*articleA] = 1;

		if (articleK)
		{
			auto discountK = articleK->GetPrice() * discount;
			if (discountInfo.discount < discountK)
			{
				discountInfo.discount = discountK;
				discountInfo.discountedArticles[*articleK] = 1;
			}
		}
		if (articleL)
		{
			auto discountL = articleL->GetPrice() * discount;
			if (discountInfo.discount < discountL)
			{
				discountInfo.discount = discountL;
				discountInfo.discountedArticles[*articleL] = 1;
			}
		}
		else if(articleM)
		{
			auto discountM = articleM->GetPrice() * discount;
			if (discountInfo.discount < discountM)
			{
				discountInfo.discount = discountM;
				discountInfo.discountedArticles[*articleM] = 1;
			}
		}
	}

	return discountInfo;
}

}
}