string的一些操作：





```c++
std::string to_string( int value );
(1)	(since C++11)
std::string to_string( long value );
(2)	(since C++11)
std::string to_string( long long value );
(3)	(since C++11)
std::string to_string( unsigned value );
(4)	(since C++11)
std::string to_string( unsigned long value );
(5)	(since C++11)
std::string to_string( unsigned long long value );
(6)	(since C++11)
std::string to_string( float value );
(7)	(since C++11)
std::string to_string( double value );
(8)	(since C++11)
std::string to_string( long double value );
(9)	(since C++11)

to_string() 把整形或者浮点型转成字符串，但是最好拿来转整型，转浮点型结果会无法意料。
atoi()  把c风格的字符串转成整数，一般这样用atoi(s.c_str()); s是std::string 先转成c风格字符串。
int atoi (const char * str);
Convert string to integer

stoi(s)  把std::string 转成10进制整数 


C++11 introduces std::stoi (and variants for each numeric type) and std::to_string, the counterparts of the C atoi and itoa but expressed in term of std::string.
```

