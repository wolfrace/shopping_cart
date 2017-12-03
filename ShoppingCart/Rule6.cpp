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

double CRule6::GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const
{
	double result = 0;

	size_t nArticles = articles.size();

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleC = GetArticle(articles, constants::ArticleId::C);

	nArticles -= articleA != nullptr ? 1 : 0;
	nArticles -= articleC != nullptr ? 1 : 0;

	if (nArticles == 4)
	{
		result = total * discount;
	}

	return result;
}

}
}