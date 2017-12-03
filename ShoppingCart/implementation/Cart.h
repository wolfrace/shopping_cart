#pragma once
#include "ICart.h"
#include "IRule.h"
#include "Article.h"

namespace store
{
namespace impl
{

class CCart
	: public ICart
{
public:
	CCart(std::vector<IRuleUniquePtr> && rules);

	void AddArticle(CArticle const& article) final;

	double CalculateCost() const final;

private:
	double GetTotal(ArticleStorage const& articles) const;

private:
	std::vector<IRuleUniquePtr> m_rules;

	ArticleStorage m_articles;
};

}
}