#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// 3 articles rule
class CRule5
	: public ARule
{
public:
	double GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}