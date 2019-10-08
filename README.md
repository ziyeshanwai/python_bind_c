# python_bind_c
wrap C++ code to python moudle
some useful funciotion for data typy convettion between C++ and python: 
1. C++ std<vector> convert to list  
2. python list convert to C++ std<vector>  
一些注意事项： 
1. boost 库最好重新编译
2. 注意一些boost的引用, boost库的版本与python的版本最好匹配, boost wrap C++ 用boost库1.71版本，boost 1.67有问题  
3. 注意这个的#define BOOST_PYTHON_STATIC_LIB使用  
4. 设置生成类型为动态库dll  
5. 动态库生成后把名字改为BOOST_PYTHON_MODULE（）括弧中的名称.pyd文件  
6. python中import moudle
