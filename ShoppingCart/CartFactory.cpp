#include "stdafx.h"
#include "CartFactory.h"
#include "IRule.h"
#include "Cart.h"
#include "Rule1.h"
#include "Rule2.h"
#include "Rule3.h"
#include "Rule4.h"
#include "Rule5.h"
#include "Rule6.h"
#include "Rule7.h"

namespace store
{

store::ICartUniquePtr CCartFactory::CreateCart()
{
	std::vector<IRuleUniquePtr> rules;

	rules.emplace_back(std::make_unique<impl::CRule1>());
	rules.emplace_back(std::make_unique<impl::CRule2>());
	rules.emplace_back(std::make_unique<impl::CRule3>());
	rules.emplace_back(std::make_unique<impl::CRule4>());
	rules.emplace_back(std::make_unique<impl::CRule5>());
	rules.emplace_back(std::make_unique<impl::CRule6>());
	rules.emplace_back(std::make_unique<impl::CRule7>());

	return std::make_unique<impl::CCart>(std::move(rules));
}

}