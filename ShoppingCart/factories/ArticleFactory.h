#pragma once
#include "Article.h"

namespace store
{

class CArticleFactory
{
public:
	static CArticle CreateArticle(constants::ArticleId const& id);
};

}