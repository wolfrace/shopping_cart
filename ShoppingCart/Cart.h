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

	void AddArticle(IArticleSharedPtr const& article) final;
	double CalculateCost() const final;

private:
	double GetTotal(std::map<IArticleSharedPtr, size_t> const& articles) const;

private:
	std::vector<IRuleUniquePtr> m_rules;

	std::map<IArticleSharedPtr, size_t> m_articles;
};

}
}