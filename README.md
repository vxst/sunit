# SUNIT

This project is the open source version of my old unit test libraries for many of my private C++ projects.

## Interface

The functions defined in namespace sunit.

```c++
void test_start(const char* unit_name);
void test_start_with_log(const char* unit_name, const char* log_file_name);
void test_end();

void test(const char* component_name, bool condition);
void test_fequal(const char* component_name, double a, double b);
void test_likely(const char* component_name, double probability, bool condition);
```

## Usage

### Install

```bash
make
make install
```

### Example usage

```c++
#include <sunit.c>
#include <climits>

using namespace sunit;

int add(int a, int b){
	return a + b;
}

int main(){
	test_start("add");
	test("positive", add(1, 3) == 4);
	test("negative", add(-1, -3) == -4);
	test("cross", add(1, -1) == 0);
	test("buggy", add(INT_MAX, INT_MAX) == (long long) INT_MAX * 2ll);
	test_end();
}
```

Compile it with c++ test.cpp -lsunit -o test, and run ./test, if right, you will get following result:

[example](http://showterm.io/25a808b0446d76cbe8360)
```
Start Testing add
Error Testing add buggy
Stop Testing add
```

> Copyright (C) 2016  Shan Ting <vxst@vxst.org>
> 
> This program is free software: you can redistribute it and/or modify
> it under the terms of the GNU General Public License as published by
> the Free Software Foundation, either version 3 of the License, or
> (at your option) any later version.
> 
> This program is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
> GNU General Public License for more details.
> 
> You should have received a copy of the GNU General Public License
> along with this program.  If not, see <http://www.gnu.org/licenses/>.

