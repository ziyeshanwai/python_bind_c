// Author: Thomas Arvanitidis
// URL:    https://github.com/thomasarvanitidis/boost_python_package
#define BOOST_PYTHON_STATIC_LIB  
#include "boost/python/module.hpp"
#include "boost/python/def.hpp"
#include "boost/python/numpy.hpp"
#include "fastmatrix.h"

namespace p = boost::python;

/***************************/
/* PYTHON MODULE INTERFACE */
/***************************/

BOOST_PYTHON_FUNCTION_OVERLOADS(add, fastmatrix::add, 2, 2)

BOOST_PYTHON_MODULE(wr2)
{

    p::def("supper_fast_addition", fastmatrix::supper_fast_addition);

    p::def("add", fastmatrix::add, add(
      (p::arg("a"),
       p::arg("b")
     )));

}
/* demo use string
std::string greet()
{
	return "hello, dude !!";
}

BOOST_PYTHON_MODULE(hello)
{
	p::def("greet", greet);
}
*/