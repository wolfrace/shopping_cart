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
	boost::optional<CArticle> GetArticle(ArticleStorage const& articles, constants::ArticleId const& id) const;
};

}
}