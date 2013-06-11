/*
 * skeletonParser.cpp
 *
 *  Created on: 11 juin 2013
 *      Author: audric
 */


#define BOOST_SPIRIT_DEBUG
#include <boost/fusion/adapted.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

#include  "include/Maillon.h"
#include  "include/SimpleLinkList.h"


namespace qi = boost::spirit::qi;
namespace spirit = boost::spirit;


namespace boost { namespace spirit { namespace traits {

template <typename T>
struct container_value<SimpleLinkList<T>, void> {
	typedef T type;
};

template <typename T>
struct push_back_container<SimpleLinkList<T>, T, void> {
	static bool call(SimpleLinkList<T>& c, T const& val) {
		c.pushBack(val);
		return true;
	}
};

}}}

struct rowType
{
	unsigned int number;
	SimpleLinkList<unsigned int> etage1, etage2;
};


struct problemType
{
	unsigned int nbSommet;
	//SimpleLinkList<unsigned int> list1, list2;
};

BOOST_FUSION_ADAPT_STRUCT(rowType, (unsigned int, number)(SimpleLinkList<unsigned int>, etage1)(SimpleLinkList<unsigned int>, etage2))
BOOST_FUSION_ADAPT_STRUCT(problemType, (unsigned int, nbSommet))



template<typename Iterator>
struct parser_expression : qi::grammar<Iterator, rowType(), qi::space_type>
{
	parser_expression() : parser_expression::base_type(start)
	{

		etage  = '[' >> -(qi::int_ % ',') >> ']';
		start = qi::int_ >> etage >> -etage >> '=';
	}

	qi::rule<Iterator, rowType(), qi::space_type> start;
	qi::rule<Iterator, SimpleLinkList<unsigned int>(), qi::space_type> etage;
};




template<typename Iterator>
struct problem_parser : qi::grammar<Iterator,problemType(), qi::space_type >
{

	problem_parser() : problem_parser::base_type(start)
	{
		using qi::_val;
		using qi::_a;
		using qi::eps;
		using boost::phoenix::bind;

		start = qi::int_ >> '_' >> +(row_parser);
		//BOOST_SPIRIT_DEBUG_NODE(start);
	}

	qi::rule<Iterator, problemType(), qi::space_type> start;
	parser_expression<Iterator> row_parser;
};


void test(const std::string input)
{
	static const parser_expression<std::string::const_iterator> p;

	rowType parsed;
	std::string::const_iterator f(input.begin()), l(input.end());
	bool ok = qi::phrase_parse(f, l, p, qi::space, parsed);


	if (ok)

		std::cout << "Result: " << parsed.number << " " << parsed.etage1 << parsed.etage2 << std::endl;
	else
		std::cout << "Parse failed\n";

	if (f!=l)
		std::cout << "Unparsed: '" << std::string(f,l) << "'\n";
}



void test_pb(const std::string input)
{

	static const problem_parser<std::string::const_iterator> p;

	problemType pb;

	std::string::const_iterator f(input.begin()), l(input.end());
	bool ok = qi::phrase_parse(f, l, p, qi::space, pb);

	if (ok)
		std::cout << "Result: "  << pb.nbSommet;//<< parsed.number << " " << parsed.list1 << parsed.list2 << std::endl;
	else
		std::cout << "Parse failed\n";

	if (f!=l)
		std::cout << "Unparsed: '" << std::string(f,l) << "'\n";
}


int main()
{
	test_pb("9_ 1 [2, 3, 4] [5, 6]");
	/*test("2 []        [6, 7] =");
	test("3 [4, 5, 6] [    ] =");
	test("4 [5, 6, 7]        =");*/
}
