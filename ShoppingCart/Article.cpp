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

bool CArticle::operator<(CArticle const& rhs) const
{
	return m_id < rhs.m_id;
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