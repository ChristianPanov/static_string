Experimental compile-time string manipulation C++17 library
# Install
```
git clone --recursive https://github.com/ChristianPanov/static_string
```
# Features
- Written in modern C++17
- Compile-time
- std::string-like interface
# Usage
## Basic Usage
```cpp
#include "static_string.h"

#include <iostream>

int main()
{
	constexpr cts::static_string<char, 14> str = "Compile-time ";
	constexpr cts::static_string<char, 7> str2 = "string";

	static_assert(str2.size() == 6);
	static_assert(str.empty() == false);
	static_assert(str[1] == 'o');
	static_assert(str.contains("Compile") == true);
	static_assert(str.contains("Runtime") == false);

	static_assert(str + str2 == "Compile-time string");
	static_assert(str != str2);

	std::cout << str + str2 << '\n';

	return 0;
}
```
**NOTE:** When initializing the string object on instantiation, the template arguments can be deduced, thus, can be omitted.
#### Example
```cpp
#include "static_string.h"

int main()
{
	constexpr cts::static_string str = "Compile-time string";

	return 0;
}
```
## Find Substring
```cpp
#include "static_string.h"

int main()
{
	constexpr cts::static_string str = "Compile-time string time";

	//By default, the position offset is 0
	static_assert(str.find("time") == 8);

	//Find substring after a given position
	static_assert(str.find<9>("time") == 20);

	static_assert(str.rfind("time") == 20);

	//Find substring after a given position
	static_assert(str.rfind<20>("time") == 8);

	return 0;
}
```
## Return Substring and Reversed Substring
```cpp
#include "static_string.h"

int main()
{
	constexpr cts::static_string str = "Compile-time string time";

	static_assert(str.substr<0, 6>() == "Compile");
	static_assert(str.substr<str.find("time"), 11>() == "time");

	static_assert(str.rsubstr<str.find("time"), 11>() == "emit");

	return 0;
}
```
## Replace Substring
```cpp
#include "static_string.h"

int main()
{
	constexpr cts::static_string str = "Compile-time string time";
	constexpr auto replaced = str.replace<str.find("time"), str.find("time") + 4>("REPLACED");

	static_assert(replaced == "Compile-REPLACED string time");

	return 0;
}
```
## Starts With & Ends With
```cpp
#include "static_string.h"

int main()
{
	constexpr cts::static_string url = "https://cppreference.com";

	static_assert(url.starts_with("https"));
	static_assert(!url.starts_with("ftp"));
	static_assert(url.ends_with(".com"));
	static_assert(!url.ends_with(".org"));

	return 0;
}
```
