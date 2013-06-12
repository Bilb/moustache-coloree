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

#include <iterator>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>

#include <vector>
#include <fstream>

#include  "include/Maillon.h"
#include  "include/ColorClass.h"
#include  "include/SimpleLinkList.h"


namespace qi = boost::spirit::qi;
namespace spirit = boost::spirit;
namespace ascii = boost::spirit::ascii;


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
	std::vector<rowType> rows;
	//SimpleLinkList<unsigned int> list1, list2;
};



BOOST_FUSION_ADAPT_STRUCT(rowType, (unsigned int, number)(SimpleLinkList<unsigned int>, etage1)(SimpleLinkList<unsigned int>, etage2))
BOOST_FUSION_ADAPT_STRUCT(problemType, (unsigned int, nbSommet)(std::vector<rowType>, rows))



template<typename Iterator>
struct row_parser : qi::grammar<Iterator, rowType(), qi::space_type>
{
	row_parser() : row_parser::base_type(start)
	{

		etage  = '[' >> -(qi::int_ % ',') >> ']';
		start = qi::int_ >> etage >> -etage;
	}

	qi::rule<Iterator, rowType(), qi::space_type> start;
	qi::rule<Iterator, SimpleLinkList<unsigned int>(), qi::space_type> etage;
};




template<typename Iterator>
struct problem_parser : qi::grammar<Iterator,problemType(),qi::space_type>
{

	problem_parser() : problem_parser::base_type(start)
	{
		using qi::_val;
		using qi::_a;
		using qi::eps;
		using boost::phoenix::bind;
		using qi::lit;

		start = qi::int_ >> lit('_') >> +(row);

		//BOOST_SPIRIT_DEBUG_NODE(start);
	}

	qi::rule<Iterator, problemType(),qi::space_type> start;
	row_parser<Iterator> row;
};




bool parseFile(const std::string charpenteFile, problemType& pb)
{
	typedef std::istream_iterator<char> base_iterator_type;
	static const problem_parser<spirit::multi_pass<base_iterator_type> > p;
	namespace spirit = boost::spirit;

	using spirit::ascii::char_;
	using spirit::qi::double_;
	using spirit::qi::eol;

	//std::ifstream in("D:\\multi_pass.txt");
	std::ifstream in(charpenteFile.c_str());
	if (!in.is_open()) {
		std::cout << "Could not open input file: '" << charpenteFile << "'" <<
				std::endl;
		return false;
	}



	spirit::multi_pass<base_iterator_type> first = spirit::make_default_multi_pass(base_iterator_type(in));
	spirit::multi_pass<base_iterator_type> last = spirit::make_default_multi_pass(base_iterator_type());


	bool ok = spirit::qi::phrase_parse(first, last ,
			p,
			qi::space,
			pb);

	if (ok && first == last) {
		return true;
	}
	else
		std::cout << "Parse of input file failed\n";

	if (first!=last)
		std::cout << "Unparsed: '" << std::string(first,last) << "'\n";

	return false;
}


//std::string::const_iterator f(input.begin()), l(input.end());
//bool ok = qi::phrase_parse(f, l, p, qi::space, pb);


