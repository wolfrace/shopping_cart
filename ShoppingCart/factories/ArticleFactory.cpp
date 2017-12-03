#include "stdafx.h"
#include "ArticleFactory.h"
#include "Article.h"
#include "ArticlePrices.h"

namespace store
{

CArticle store::CArticleFactory::CreateArticle(constants::ArticleId const& id)
{
	return CArticle(id, constants::ArticlePrices.at(id));
}

}