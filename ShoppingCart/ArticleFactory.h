#pragma once
#include "IArticle.h"

namespace store
{

class CArticleFactory
{
	IArticleSharedPtr CreateArticle(constants::ArticleId const& id) const;
};

}