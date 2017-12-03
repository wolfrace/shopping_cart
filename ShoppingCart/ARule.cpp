#include "stdafx.h"
#include "ARule.h"

namespace store
{
namespace impl
{

boost::optional<CArticle> ARule::GetArticle(ArticleStorage const& articles, constants::ArticleId const& id) const
{
	auto it = std::find_if(articles.cbegin(), articles.cend(), [id](auto& elem) {
		return elem.first.GetId() == id;
	});

	if (it != articles.cend())
	{
		assert(it->second > 0);
		return it->first;
	}
	else
	{
		return boost::none;
	}
}

}
}