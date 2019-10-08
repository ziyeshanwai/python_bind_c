#define BOOST_PYTHON_STATIC_LIB  
#include <iostream>
#include "boost/python.hpp"
#include "boost/python/stl_iterator.hpp"
#include "fastmatrix.h"

namespace fastmatrix
{

// Converts a python list to a C++ vector.
template<typename T>
inline
std::vector<T> to_std_vector(const p::object& iterable)
{
    return std::vector<T>(p::stl_input_iterator<T>(iterable),
                          p::stl_input_iterator<T>());
}

// Converts a C++ vector to a python list.
template <class T>
inline
p::list to_python_list(std::vector<T> vector)
{
    typename std::vector<T>::iterator iter;
    p::list list;
    for (iter = vector.begin(); iter != vector.end(); ++iter)
    {
        list.append(*iter);
    }

    return list;
}

void supper_fast_addition(std::vector<double>& a, std::vector<double>& b,
                          std::vector<double>& out)
{
    if (a.size() != b.size()
        && a.size() != out.size())
        std::cout << "Vectors should be of same size.\n";

    for (int n = 0; n < b.size(); ++n)
    {
        out[n] = a[n] + b[n];
    }
}

p::list add(p::list a, p::list b)
{
    std::vector<double> output (boost::python::len(a)); //���캯��
    std::vector<double> a_ (to_std_vector<double>(a));
    std::vector<double> b_ (to_std_vector<double>(b));
	std::vector<double>::iterator ite = a_.begin(); //��ӡstd::vector �Ĳ���
	for (; ite != a_.end(); ite++)
	{
		std::cout <<"in add "<< *ite <<"endl\n"<< std::endl;
	}
    supper_fast_addition(a_, b_, output);

    return to_python_list<double>(output);
}

} // End of namespace fastmatrix
