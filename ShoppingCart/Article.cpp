#include "stdafx.h"
#include "Article.h"

namespace store
{
namespace impl
{
CArticle::CArticle(constants::ArticleId id, double price)
	: m_id(id)
	, m_price(price)
{
}

constants::ArticleId CArticle::GetId() const
{
	return m_id;
}

double CArticle::GetPrice() const
{
	return m_price;
}

}
}