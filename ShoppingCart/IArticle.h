#pragma once
#include "ArticleIds.h"

namespace store
{

class IArticle
{
public:
	virtual ~IArticle() = default;

	virtual constants::ArticleId GetId() const = 0;
	virtual double GetPrice() const = 0;
};

using IArticleSharedPtr = std::shared_ptr<IArticle>;

}