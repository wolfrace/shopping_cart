#pragma once
#include "IArticle.h"

namespace store
{

class CArticleFactory
{
public:
	static IArticleSharedPtr CreateArticle(constants::ArticleId const& id);
};

}