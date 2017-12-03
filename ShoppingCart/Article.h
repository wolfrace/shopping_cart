#pragma once
#include "IArticle.h"

namespace store
{
namespace impl
{

class CArticle
	: public IArticle
{
public:
	CArticle(constants::ArticleId id, double price);

	constants::ArticleId GetId() const final;
	double GetPrice() const final;

private:
	constants::ArticleId m_id;
	double m_price;
};

}
}