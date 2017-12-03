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

double CRule3::GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double /*total*/) const
{
	double total = 0;

	auto articleE = GetArticle(articles, constants::ArticleId::E);
	auto articleF = GetArticle(articles, constants::ArticleId::F);
	auto articleG = GetArticle(articles, constants::ArticleId::G);

	if (articleE != nullptr && articleF != nullptr && articleG != nullptr)
	{
		size_t nPair = std::min(std::min(articles.at(articleE), articles.at(articleF)), articles.at(articleG));

		total += articleE->GetPrice() * nPair * discount;
		total += articleF->GetPrice() * nPair * discount;
		total += articleG->GetPrice() * nPair * discount;
	}

	return total;
}

}
}