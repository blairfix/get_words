#include <Rcpp.h>
#include <string>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/regex.hpp>
#include <boost/range/algorithm_ext/erase.hpp>

// Sys.setenv("PKG_LIBS"="-lboost_regex")


using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

std::list<std::string> get_words( std::string &x )
{

    // to lower case
    boost::algorithm::to_lower(x);

    // remove <em>
    boost::algorithm::replace_all(x, "<em>", "");

    // split on non alpha
    std::list<std::string> words;
    boost::split_regex(words, x, boost::regex( "[^a-z]" ));

    // remove empty strings
    auto blank = [] (std::string element) { return element == ""; };
    boost::remove_erase_if(words, blank);

    return words;

}

