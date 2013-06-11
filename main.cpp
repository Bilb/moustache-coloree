/*
 * main.cpp
 *
 *  Created on: 1 juin 2013
 *      Author: julien
 */



#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/spirit/include/karma_eps.hpp>

 /* fusion */
#include <boost/fusion/adapted/adt/adapt_adt.hpp>
#include <boost/fusion/include/adapt_adt.hpp>


#include <string>
#include <iostream>

#include "include/SimpleLinkList.h"
#include "include/ColorClass.h"
#include "include/ColorClassProblem.h"
#include "include/Etage.h"
#include "include/Contrainte.h"






#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;
namespace fusion = boost::fusion;

namespace client
{
    template <typename A, typename B>
    struct data
    {
        A a;
        B b;
    };

    template <typename Iterator, typename A, typename B>
    struct data_grammar : qi::grammar<Iterator, data<A, B>()>
    {
        data_grammar() : data_grammar::base_type(start)
        {
            start = real_start;
            real_start = qi::auto_ >> ',' >> qi::auto_;
        }

        qi::rule<Iterator, data<A, B>()> start;
        qi::rule<Iterator, fusion::vector<A&, B&>()> real_start;
    };
}

namespace boost { namespace spirit { namespace traits
{
    template <typename A, typename B>
    struct transform_attribute<client::data<A, B>, fusion::vector<A&, B&>, qi::domain>
    {
        typedef fusion::vector<A&, B&> type;

        static type pre(client::data<A, B>& val) { return type(val.a, val.b); }
        static void post(client::data<A, B>&, fusion::vector<A&, B&> const&) {}
        static void fail(client::data<A, B>&) {}
    };
}}}



/*

namespace client
{
    template <typename A, typename B>
    struct data
    {
        A a;
        B b;
    };

    template <typename Iterator, typename A, typename B>
    struct data_grammar : qi::grammar<Iterator, data<A, B>()>
    {
        data_grammar() : data_grammar::base_type(start)
        {
            start = real_start;
            real_start = qi::auto_ >> ',' >> qi::auto_;
        }

        qi::rule<Iterator, data<A, B>()> start;
        qi::rule<Iterator, fusion::vector<A&, B&>()> real_start;
    };
}*/








///////////////////////////////////////////////////////////////////////////////
    /*
int main()
{
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "\t\tA parser for Spirit utilizing an adapted template ...\n\n";
    std::cout << "/////////////////////////////////////////////////////////\n\n";

    std::cout << "Give me two comma separated integers:\n";
    std::cout << "Type [q or Q] to quit\n\n";

    std::string str;
    client::data_grammar<std::string::const_iterator, long, int> g; // Our grammar
    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        client::data<long, int> d;
        std::string::const_iterator iter = str.begin();
        std::string::const_iterator end = str.end();
        bool r = phrase_parse(iter, end, g, qi::space, d);

        if (r && iter == end)
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << "got: " << d.a << "," << d.b << std::endl;
            std::cout << "\n-------------------------\n";
        }
        else
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "-------------------------\n";
        }
    }

    return 0;
}*/




























using namespace std;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;




template<typename Iterator>
struct charpenteParser : qi::grammar<Iterator,ascii::space_type> 
{
	charpenteParser() : charpenteParser::base_type(start) {
		using qi::double_;
		using qi::int_;
		using boost::spirit::qi::char_; 
		using qi::alpha;
		using qi::alnum;
		using qi::digit;
		using qi::eps;
		using qi::_val;
		using boost::phoenix::bind;


		
		
		
		
		start = +(sommet >> etage1 >> etage2 ) >> char_('='); 
		
			
		 
		sommet = +(digit);
		etage1 = ('[' >> sommet >> *(char_(',') >> sommet ) >> char_(']')) | (char_('[') >> char_(']'));
		etage2 = ('[' >> sommet >> *(char_(',') >> sommet ) >> char_(']')) | -(char_('[') >> char_(']'));
	}



	qi::rule<Iterator,ascii::space_type> start;
	
	qi::rule<Iterator,ascii::space_type> sommet;
	qi::rule<Iterator,ascii::space_type> etage1;
	qi::rule<Iterator,ascii::space_type> etage2;
};






/*
int main() {
	using qi::double_;
    using qi::phrase_parse;
    using ascii::space;

	typedef std::string::const_iterator iterator_type;
	typedef charpenteParser<iterator_type> expression;

	std::string str;
	expression expression_parser;


	while(std::getline(std::cin,str)) {
	    iterator_type first = str.begin();
	    iterator_type last = str.end();

	    bool r = phrase_parse(
	        first,
	        last,
	        expression_parser,
	        space
	    );
	    if (first != last) // fail if we did not get a full match
	    	std::cout << "failed" << std::endl;
	   	else
	   		std::cout << "ok" << std::endl;
    }

	return 0;
}
*/


















/*
int main(int argc, char* argv[]) {








	string test("test");
	ColorClassProblem problem(test);

	cout << "problem INITIAL" << problem << endl;
	problem.resolve(test);

	cout << "problem RESOLVED" << problem << endl;


	return 0;
}

*/
