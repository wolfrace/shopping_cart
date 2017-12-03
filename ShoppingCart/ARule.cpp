#include "stdafx.h"
#include "ARule.h"

namespace store
{
namespace impl
{

store::IArticleSharedPtr ARule::GetArticle(std::map<IArticleSharedPtr, size_t> const& articles, constants::ArticleId const& id) const
{
	auto it = std::find_if(articles.cbegin(), articles.cend(), [id](auto& elem) {
		return elem.first->GetId() == id;
	});

	if (it != articles.cend() && it->second > 0)
	{
		return it->first;
	}
	else
	{
		return nullptr;
	}
}

}
}