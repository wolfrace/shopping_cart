// ShoppingCart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ArticleFactory.h"
#include "CartFactory.h"

bool AreSame(double a, double b)
{
	return fabs(a - b) < 0.001;
}

int main()
{

	// rule A&B test
	{
		using namespace store::constants;

		auto cart = store::CCartFactory::CreateCart();
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));

		auto total = cart->CalculateCost();
		assert(AreSame(total, 2.7));

		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));

		total = cart->CalculateCost();
		assert(AreSame(total, 6.4));
	}

    return 0;
}
