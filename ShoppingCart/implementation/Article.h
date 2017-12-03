#pragma once
#include "../interfaces/IArticle.h"

namespace store
{

class CArticle
	: public IArticle
{
public:
	CArticle(constants::ArticleId id, double price);

	bool operator<(CArticle const& rhs) const;

	constants::ArticleId GetId() const final;
	double GetPrice() const final;

private:
	constants::ArticleId m_id;
	double m_price;
};

using ArticleStorage = std::map<CArticle, size_t>;

}