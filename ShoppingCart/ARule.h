#pragma once
#include "IRule.h"

namespace store
{
namespace impl
{

class ARule
	: public IRule
{
protected:
	IArticleSharedPtr GetArticle(std::map<IArticleSharedPtr, size_t> const& articles, constants::ArticleId const& id) const;
};

}
}