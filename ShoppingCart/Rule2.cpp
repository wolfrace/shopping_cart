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

double CRule2::GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double /*total*/) const
{
	double total = 0;

	auto articleD = GetArticle(articles, constants::ArticleId::D);
	auto articleE = GetArticle(articles, constants::ArticleId::E);

	if (articleD != nullptr && articleE != nullptr)
	{
		size_t nPair = std::min(articles.at(articleD), articles.at(articleE));

		total += articleD->GetPrice() * nPair * discount;
		total += articleE->GetPrice() * nPair * discount;
	}

	return total;
}

}
}