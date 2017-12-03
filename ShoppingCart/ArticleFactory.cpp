#include "stdafx.h"
#include "ArticleFactory.h"
#include "Article.h"
#include "ArticlePrices.h"

namespace store
{

IArticleSharedPtr store::CArticleFactory::CreateArticle(constants::ArticleId const& id) const
{
	return std::make_shared<impl::CArticle>(id, constants::ArticlePrices.at(id));
}

}