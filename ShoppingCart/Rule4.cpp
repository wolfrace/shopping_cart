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

double CRule4::GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double /*total*/) const
{
	double total = 0;

	auto articleA = GetArticle(articles, constants::ArticleId::A);

	auto articleK = GetArticle(articles, constants::ArticleId::K);
	auto articleL = GetArticle(articles, constants::ArticleId::L);
	auto articleM = GetArticle(articles, constants::ArticleId::M);

	if (articleA != nullptr && 
		articleK != nullptr || articleL != nullptr || articleM != nullptr)
	{
		if (articleK != nullptr)
		{
			total = std::max(total, articleK->GetPrice() * discount);
		}
		if (articleL != nullptr)
		{
			total = std::max(total, articleL->GetPrice() * discount);
		}
		else if(articleM != nullptr)
		{
			total = std::max(total, articleM->GetPrice() * discount);
		}
	}

	return total;
}

}
}