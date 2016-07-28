# Copyright (C) 2016  Shan Ting <vxst@vxst.org>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


AR=ar
CXX=g++

libsunit.a: sunit.o
	$(AR) rcs libsunit.a sunit.o

install:
	cp libsunit.a /usr/local/lib/
	cp sunit.h /usr/local/include/

sunit.o: sunit.cpp sunit.h
	$(CXX) -std=c++11 sunit.cpp -c $(CXXFLAGS) -O3

clean:FORCE
	rm -f *.o *.a

FORCE:
