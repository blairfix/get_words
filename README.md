# get_words

A function to extract the words in a string.

### Inputs

```R
get_words(x)
```

* `x` = a string to extract words



### Output

Returns a vector containing all the words in `x`.


### Example:

```R
library(Rcpp)
Sys.setenv("PKG_LIBS"="-lboost_regex")
sourceCpp("get_words.cpp")

# example string
x = "<em>This<em>  %sentence*  ?is, \tfull of weird 60 @stuff! ^"

# get words
words = get_words(x)

```

Returns:

```
[1] "this"     "sentence" "is"       "full"     "of"       "weird"    "mstuff" 
```



### Installation

To use `get_words`, install the following R packages:
 * [Rcpp](https://cran.r-project.org/web/packages/Rcpp/index.html) 
 * [BH](https://cran.r-project.org/web/packages/BH/index.html) 
 

Put the source code (`get_words.cpp`) in the directory of your R script. 
Then source it with the command:

```
Sys.setenv("PKG_LIBS"="-lboost_regex")
sourceCpp('get_words.cpp')
```

