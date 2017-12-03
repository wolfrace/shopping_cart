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

double CRule1::GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double /*total*/) const
{
	double total = 0;

	auto articleA = GetArticle(articles, constants::ArticleId::A);
	auto articleB = GetArticle(articles, constants::ArticleId::B);

	if (articleA != nullptr && articleB != nullptr)
	{
		size_t nPair = std::min(articles.at(articleA), articles.at(articleB));

		total += articleA->GetPrice() * nPair * discount;
		total += articleB->GetPrice() * nPair * discount;
	}

	return total;
}

}
}