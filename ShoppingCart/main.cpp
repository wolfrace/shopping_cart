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

	// A&B test
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

	// D&E test
	{
		using namespace store::constants;

		auto cart = store::CCartFactory::CreateCart();
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::E));

		auto total = cart->CalculateCost();
		assert(AreSame(total, 8.55));

		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::E));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::E));

		total = cart->CalculateCost();
		assert(AreSame(total, 22.1));
	}

	// E&F&G + rule3 test
	{
		using namespace store::constants;

		auto cart = store::CCartFactory::CreateCart();
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::E));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::G));

		auto total = cart->CalculateCost();
		assert(AreSame(total, 17.1));

		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::E));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::G));
		cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::E));

		total = cart->CalculateCost();
		assert(AreSame(total, 39.2));
	}

	// A&[K,L,M] test
	{
		using namespace store::constants;

		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::K));

			auto total = cart->CalculateCost();
			assert(AreSame(total, 11.45));
		}
		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::L));

			auto total = cart->CalculateCost();
			assert(AreSame(total, 12.4));
		}
		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::M));

			auto total = cart->CalculateCost();
			assert(AreSame(total, 13.35));
		}
	}

	// rule3 test
	{
		using namespace store::constants;

		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));

			auto total = cart->CalculateCost();
			assert(AreSame(total, 11.));
		}
		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::C));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));

			auto total = cart->CalculateCost();
			assert(AreSame(total, 9.));
		}
		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));

			auto total = cart->CalculateCost();
			assert(AreSame(total, 11.4));
		}
	}

	// rule4 test
	{
		using namespace store::constants;

		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::A));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::K));

			auto total = cart->CalculateCost();
			//A&K triggered
			assert(AreSame(total, 21.45));
		}
		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::C));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::K));

			auto total = cart->CalculateCost();
			//rule3 triggered
			assert(AreSame(total, 19.15));
		}
		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::K));

			auto total = cart->CalculateCost();
			//rule4 triggered
			assert(AreSame(total, 20.7));
		}
	}

	// rule5 test
	{
		using namespace store::constants;

		{
			auto cart = store::CCartFactory::CreateCart();
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::B));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::D));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::F));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::K));
			cart->AddArticle(store::CArticleFactory::CreateArticle(ArticleId::M));

			auto total = cart->CalculateCost();
			//rule5 triggered
			assert(AreSame(total, 28.8));
		}
	}

    return 0;
}
