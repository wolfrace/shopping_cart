#include "stdafx.h"
#include "Rule7.h"

namespace store
{
namespace impl
{

namespace
{

constexpr auto discount = 0.2;

}

double CRule7::GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const
{
	double result = 0;

	size_t nArticles = articles.size();

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleC = GetArticle(articles, constants::ArticleId::C);

	nArticles -= articleA != nullptr ? 1 : 0;
	nArticles -= articleC != nullptr ? 1 : 0;

	if (nArticles >= 5)
	{
		result = total * discount;
	}

	return result;
}

}
}