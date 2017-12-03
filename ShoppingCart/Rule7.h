#pragma once
#include "ARule.h"

namespace store
{
namespace impl
{

// 5 articles rule
class CRule7
	: public ARule
{
public:
	double GetDiscount(std::map<IArticleSharedPtr, size_t> const& articles, double total) const final;

};

}
}