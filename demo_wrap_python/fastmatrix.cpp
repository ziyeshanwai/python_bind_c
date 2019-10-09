#define BOOST_PYTHON_STATIC_LIB  
#include <iostream>
#include "boost/python.hpp"
#include "boost/python/stl_iterator.hpp"
#include "fastmatrix.h"
#include  <opencv2/opencv.hpp>

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
	std::cout << "a.size is  " << a.size() << std::endl;
    /*
	for (int n = 0; n < b.size(); ++n)
    {
        out[n] = a[n] + b[n];
    }
	*/
}

void supper_fast_addition(std::vector<cv::Point2f>& a, std::vector<cv::Point2f>& b,
	std::vector<cv::Point2f>& out)
{
	if (a.size() != b.size()
		&& a.size() != out.size())
		std::cout << "Vectors should be of same size.\n";
	std::cout << "a.size is  " << a.size() << std::endl;
	/*
	for (int n = 0; n < b.size(); ++n)
	{
		out[n] = a[n] + b[n];
	}
	*/
}



p::list add(p::list a, p::list b)
{
 //   std::vector<double> output (boost::python::len(a)); //构造函数
 //   std::vector<double> a_ (to_std_vector<double>(a));
 //   std::vector<double> b_ (to_std_vector<double>(b));
	//std::vector<double>::iterator ite = a_.begin(); //打印std::vector 的操作
	std::cout << "start \n" << "len a is " << boost::python::len(a) << std::endl;
	//std::cout << "a is  " <<a.index(1) << std::endl;
	std::vector<cv::Point2f> store;
	for (int i = 0; i < boost::python::len(a); i++)
	{
		std::cout << "hahha " << std::endl;
		std::cout << boost::python::extract<float>(a[i][0]) << std::endl; // 将列表中的值解析出来
		std::cout << boost::python::extract<float>(a[i][1]) << std::endl;
		store.push_back({ boost::python::extract<float>(a[i][0]), boost::python::extract<float>(a[i][1]) }); //赋值
	}
	for (int i = 0; i < store.size(); i++)
	{
		std::cout << "store is " << store[ i ] << std::endl;
	}
	//std::vector<cv::Point2f> output(boost::python::len(a)); //构造函数
	//std::vector<cv::Point2f> a_(to_std_vector<cv::Point2f>(a));
	//std::vector<cv::Point2f> b_(to_std_vector<cv::Point2f>(b));
	//std::vector<cv::Point2f>::iterator ite = a_.begin(); //打印std::vector 的操作
	//std::cout << "开始add\n" << std::endl;
	/*for (; ite != a_.end(); ite++)
	{
		std::cout <<"in add "<< *ite <<"endl\n"<< std::endl;
	}*/
    //supper_fast_addition(a_, b_, output);
	std::vector<float> output;
	output.push_back(1.0);
    return to_python_list<float>(output);
}

} // End of namespace fastmatrix
